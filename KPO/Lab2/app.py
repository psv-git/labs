import re
import time
import requests
from lxml import html



DOMAIN = "tulipindicators.org/"
# DOMAIN = "links.qatl.ru/"
ROOT = ""
ADDR = "http://" + DOMAIN
URLS = [ADDR + ROOT]
CHECKED_URLS = set(URLS)
VALID_LINKS = []
INVALID_LINKS = []

# =============================================================================

def is_anchor(path):
    if len(path):
        return path[0] == "#"
    return False


def is_junk(path):
    m = re.search("^mailto:", path)
    p = re.search("^tel:", path)
    if not m and not p:
        return False
    return True


# def is_html(path):
#     m = re.search("\.html$", path)
#     if m is None:
#         return False
#     return True


def is_full_addr(path):
    m = re.search("^http[s]?://", path)
    w = re.search("^/[/]www.", path)
    if m is None and w is None:
        return False
    return True


def correct_path(path):
    path = re.sub("^(\.{0,2}/)*", "", path)
    return path


def is_this_domain(url):
    m = re.search(f"^http[s]?://{DOMAIN}/*", url)
    w = re.search(f"^www.{DOMAIN}/*", url)
    if m is None and w is None:
        return False
    return True


# =============================================================================
valid_file = open("valid.txt", "w")
invalid_file = open("invalid.txt", "w")

try:
    while len(URLS):
        URL = URLS.pop()
        resp = requests.get(URL)
        CODE = resp.status_code
        if CODE >= 100 and CODE < 400:
            if resp.content:
                tree = html.fromstring(resp.content)
                paths_on_page = tree.xpath("//a/@href")
                for path in paths_on_page:
                    if not is_anchor(path) and not is_junk(path):
                        if not is_full_addr(path):
                            url = ADDR + correct_path(path)
                        else:
                            url = path
                        if url not in CHECKED_URLS:
                            if is_this_domain(url):
                                CHECKED_URLS.add(url)
                                URLS.append(url)
            VALID_LINKS.append(f"{URL}  |  {CODE}\n")
        else:
            INVALID_LINKS.append(f"{URL}  |  {CODE}\n")
except Exception as e:
    print(e)

for l in VALID_LINKS:
    valid_file.write(l)
for l in INVALID_LINKS:
    invalid_file.write(l)

now = time.strftime("%d-%m-%Y %H:%M:%S")
valid_file.write(f"total count: {len(VALID_LINKS)}, date: {now}\n")
invalid_file.write(f"total count: {len(INVALID_LINKS)}, date: {now}\n")
valid_file.close()
invalid_file.close()
