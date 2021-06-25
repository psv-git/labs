from rest_framework.pagination import PageNumberPagination
from rest_framework.response import Response



class CustomPaginator(PageNumberPagination):

    page_size_query_param = "page_size"


    def _get_next_page_number(self):
        if not self.page.has_next():
            return None
        page_number = self.page.next_page_number()
        return page_number


    def _get_previous_page_number(self):
        if not self.page.has_previous():
            return None
        page_number = self.page.previous_page_number()
        return page_number


    def _get_pages_count(self):
        pages_count = self.page.paginator.count // self.page_size
        # example: total count=9, page size = 4
        # 9 // 4 = 2 full pages, but
        # 9 % 4 = 1  =>  we need +1 new page for this element
        if not self._is_last_page_full():
            pages_count += 1

        return max(pages_count, 1)


    def _is_last_page_full(self):
        if self.page.paginator.count == 0:
            return False
        return self.page.paginator.count % self.page_size == 0



class ThreadsPaginator(CustomPaginator):

    page_size = 10
    max_page_size = 20


    def get_paginated_response(self, data):
        return Response({
            "pages_data": {
                "active_page": self.page.number,
                "pages_count": self._get_pages_count(),
            },
            "results": data,
        })



class PostsPaginator(CustomPaginator):

    page_size = 10
    max_page_size = 20


    def get_paginated_response(self, data):
        return Response({
            "pages_data": {
                "active_page": self.page.number,
                "page_size": self.page_size,
                "pages_count": self._get_pages_count(),
                "items_on_page": len(data),
                "is_last_page_full": self._is_last_page_full(),
            },
            "results": data,
        })
