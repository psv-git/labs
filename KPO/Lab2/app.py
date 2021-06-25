import re
import time
import requests
from lxml import html



ADDR = "http://52.136.215.164/"
ROOT_PATH = "broken-links/"
URLS = [ADDR + ROOT_PATH]
CHECKED_URLS = set(URLS)
VALID_COUNT = 0
INVALID_COUNT = 0


# =============================================================================

def is_anchor(path):
    if len(path):
        return path[0] == "#"
    return False


def is_html(path):
    m = re.search("\.html$", path)
    if m is None:
        return False
    return True


def is_have_address(path):
    m = re.search("^http[s]?://", path)
    if m is None:
        return False
    return True


def correct_path(path):
    path = re.sub("^(\.{0,2}/)*", "", path)
    return path


def is_address_valid(url):
    m = re.search("^http[s]?://52.136.215.164/*", url)
    if m is None:
        return False
    return True


# =============================================================================
valid_file = open("valid.txt", "w")
invalid_file = open("invalid.txt", "w")

while len(URLS):
    URL = URLS.pop()

    resp = requests.get(URL)
    CODE = resp.status_code
    if CODE == 200:
        tree = html.fromstring(resp.content)
        paths_on_page = tree.xpath("//a/@href")
        for path in paths_on_page:
            if not is_anchor(path):
                if is_html(path):
                    url = ADDR + correct_path(ROOT_PATH + path)
                elif not is_have_address(path):
                    url = ADDR + correct_path(path)
                if is_address_valid(url):
                    if url not in CHECKED_URLS:
                        CHECKED_URLS.add(url)
                        URLS.append(url)
        VALID_COUNT += 1
        valid_file.write(f"{URL}    {CODE}\n")
    else:
        INVALID_COUNT += 1
        invalid_file.write(f"{URL}    {CODE}\n")

now = time.strftime("%d-%m-%Y %H:%M:%S")
valid_file.write(f"total count: {VALID_COUNT}, date: {now}\n")
invalid_file.write(f"total count: {INVALID_COUNT}, date: {now}\n")
valid_file.close()
invalid_file.close()
