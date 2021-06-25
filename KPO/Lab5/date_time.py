from datetime import datetime as dt



class DateTime:
    """
    Class represent a date-time object.
    """

    req_fields = ("year", "month", "day", "hour", "minute", "second")

# private methods =============================================================

    def __init__(self, year=None, month=None, day=None, hour=None, minute=None, second=None):
        if year and not isinstance(year, int):
            raise TypeError("In DateTime 'year' must be 'int' type.")
        if month and not isinstance(month, int):
            raise TypeError("In DateTime 'month' must be 'int' type.")
        if day and not isinstance(day, int):
            raise TypeError("In DateTime 'day' must be 'int' type.")
        if hour and not isinstance(hour, int):
            raise TypeError("In DateTime 'hour' must be 'int' type.")
        if minute and not isinstance(minute, int):
            raise TypeError("In DateTime 'minute' must be 'int' type.")
        if second and not isinstance(second, int):
            raise TypeError("In DateTime 'second' must be 'int' type.")

        datetime_dict = dict(zip(self.req_fields, (year, month, day, hour, minute, second)))
        self.__set_datetime(datetime_dict)


    def __str__(self):
        return "{0}/{1}/{2} {3}:{4}:{5}".format(
            self.datetime_dict.get("year"),
            self.datetime_dict.get("month"),
            self.datetime_dict.get("day"),
            self.datetime_dict.get("hour"),
            self.datetime_dict.get("minute"),
            self.datetime_dict.get("second")
        )


    def __eq__(self, other):
        if isinstance(other, DateTime):
            if self.get_year() != other.get_year(): return False
            elif self.get_month() != other.get_month(): return False
            elif self.get_day() != other.get_day(): return False
            elif self.get_hour() != other.get_hour(): return False
            elif self.get_minute() != other.get_minute(): return False
            elif self.get_second() != other.get_second(): return False
            else: return True
        return NotImplemented


    def __ne__(self, other):
        if isinstance(other, DateTime):
            if self.get_year() != other.get_year(): return True
            elif self.get_month() != other.get_month(): return True
            elif self.get_day() != other.get_day(): return True
            elif self.get_hour() != other.get_hour(): return True
            elif self.get_minute() != other.get_minute(): return True
            elif self.get_second() != other.get_second(): return True
            else: return False
        return NotImplemented


    def __gt__(self, other):
        if isinstance(other, DateTime):
            if self.get_year() > other.get_year(): return True
            elif self.get_year() < other.get_year(): return False
            elif self.get_month() > other.get_month(): return True
            elif self.get_month() < other.get_month(): return False
            elif self.get_day() > other.get_day(): return True
            elif self.get_day() < other.get_day(): return False
            elif self.get_hour() > other.get_hour(): return True
            elif self.get_hour() < other.get_hour(): return False
            elif self.get_minute() > other.get_minute(): return True
            elif self.get_minute() < other.get_minute(): return False
            elif self.get_second() > other.get_second(): return True
            else: return False
        return NotImplemented


    def __lt__(self, other):
        if isinstance(other, DateTime):
            if self.get_year() < other.get_year(): return True
            elif self.get_year() > other.get_year(): return False
            elif self.get_month() < other.get_month(): return True
            elif self.get_month() > other.get_month(): return False
            elif self.get_day() < other.get_day(): return True
            elif self.get_day() > other.get_day(): return False
            elif self.get_hour() < other.get_hour(): return True
            elif self.get_hour() > other.get_hour(): return False
            elif self.get_minute() < other.get_minute(): return True
            elif self.get_minute() > other.get_minute(): return False
            elif self.get_second() < other.get_second(): return True
            else: return False
        return NotImplemented


    def __set_datetime(self, datetime_dict):
        self.datetime_dict = DateTime.datetime_to_dict(dt.now())
        year = datetime_dict.get("year")
        if year: self.datetime_dict["year"] = year
        month = datetime_dict.get("month")
        if month: self.datetime_dict["month"] = month
        day = datetime_dict.get("day")
        if day: self.datetime_dict["day"] = day
        hour = datetime_dict.get("hour")
        if hour: self.datetime_dict["hour"] = hour
        minute = datetime_dict.get("minute")
        if minute: self.datetime_dict["minute"] = minute
        second = datetime_dict.get("second")
        if second: self.datetime_dict["second"] = second


# static methods ==============================================================

    @staticmethod
    def datetime_to_dict(datetime_obj):
        if not isinstance(datetime_obj, dt):
            raise TypeError("In DateTime.datetime_to_dict 'datetime_obj' must be 'datetime' type.")

        return dict(zip(DateTime.req_fields, datetime_obj.timetuple()))


    @staticmethod
    def from_datetime(datetime_obj):
        if not isinstance(datetime_obj, dt):
            raise TypeError("In DateTime.from_datetime 'datetime_obj' must be 'datetime' type.")

        return DateTime.from_dict(DateTime.datetime_to_dict(datetime_obj))


    @staticmethod
    def from_dict(datetime_dict):
        if not isinstance(datetime_dict, dict):
            raise TypeError("In DateTime.from_dict 'datetime_dict' must be 'dict' type.")

        return DateTime(
            year=datetime_dict.get("year"),
            month=datetime_dict.get("month"),
            day=datetime_dict.get("day"),
            hour=datetime_dict.get("hour"),
            minute=datetime_dict.get("minute"),
            second=datetime_dict.get("second"),
        )

# public methods ==============================================================

    # datetime ----------------------------------------------------------------

    def get_datetime(self):
        return self.datetime_dict

    # date --------------------------------------------------------------------

    def get_date(self):
        return {
            "year": self.datetime_dict.get("year"),
            "month": self.datetime_dict.get("month"),
            "day": self.datetime_dict.get("day")
        }


    def get_strdate(self):
        return "{0}/{1}/{2}".format(
            self.datetime_dict.get("year"),
            self.datetime_dict.get("month"),
            self.datetime_dict.get("day")
        )


    def get_year(self):
        return self.datetime_dict.get("year")


    def get_month(self):
        return self.datetime_dict.get("month")


    def get_day(self):
        return self.datetime_dict.get("day")

    # time --------------------------------------------------------------------

    def get_time(self):
        return {
            "hour": self.datetime_dict.get("hour"),
            "minute": self.datetime_dict.get("minute"),
            "second": self.datetime_dict.get("second")
        }


    def get_strtime(self):
        return "{0}:{1}:{2}".format(
            self.datetime_dict.get("hour"),
            self.datetime_dict.get("minute"),
            self.datetime_dict.get("second")
        )


    def get_hour(self):
        return self.datetime_dict.get("hour")


    def get_minute(self):
        return self.datetime_dict.get("minute")


    def get_second(self):
        return self.datetime_dict.get("second")
