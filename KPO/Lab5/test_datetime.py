import unittest
from datetime import datetime as dtime
from date_time import DateTime



class TestDateTime(unittest.TestCase):

    __req_fields = ("year", "month", "day", "hour", "minute", "second")

    def __datetime_to_dict(self, dtime_obj):
        return dict(zip(self.__req_fields, dtime_obj.timetuple()))

    # =========================================================================

    def test_bad_init_1(self):
        with self.assertRaises(TypeError):
            dt = DateTime(year="ololo")

    def test_bad_init_2(self):
        with self.assertRaises(TypeError):
            dt = DateTime(month="ololo")

    def test_bad_init_3(self):
        with self.assertRaises(TypeError):
            dt = DateTime(day="ololo")

    def test_bad_init_4(self):
        with self.assertRaises(TypeError):
            dt = DateTime(hour="ololo")

    def test_bad_init_5(self):
        with self.assertRaises(TypeError):
            dt = DateTime(minute="ololo")

    def test_bad_init_6(self):
        with self.assertRaises(TypeError):
            dt = DateTime(second="ololo")


    def test_bad_init_7(self):
        with self.assertRaises(TypeError):
            dt = DateTime.from_datetime("ololo")


    def test_bad_init_8(self):
        with self.assertRaises(TypeError):
            dt = DateTime.from_dict("ololo")

    # -------------------------------------------------------------------------

    def test_good_init_1(self):
        dt = DateTime(year=2019, month=11, day=7)
        self.assertIsInstance(dt, DateTime)


    def test_good_init_2(self):
        dt = DateTime.from_datetime(dtime.now())
        self.assertIsInstance(dt, DateTime)


    def test_good_init_3(self):
        dt = DateTime.from_dict({'year': 2005, 'month': 7, 'day': 14, 'hour': 12, 'minute': 30, 'second': 10})
        self.assertIsInstance(dt, DateTime)

    # -------------------------------------------------------------------------

    def test_lesser_1(self):
        dt_1 = DateTime()
        dt_2 = DateTime(second=60)
        self.assertLess(dt_1, dt_2)


    def test_greater_1(self):
        dt_1 = DateTime()
        dt_2 = DateTime(second=60)
        self.assertGreater(dt_2, dt_1)


    def test_bad_equal(self):
        dt_1 = DateTime()
        dt_2 = DateTime(second=600)
        self.assertNotEqual(dt_1, dt_2)


    def test_good_equal(self):
        dt_1 = DateTime()
        dt_2 = DateTime()
        self.assertEqual(dt_1, dt_2)


    def test_bad_not_equal(self):
        dt_1 = DateTime()
        dt_2 = DateTime()
        self.assertEqual(dt_1, dt_2)

    def test_good_not_equal(self):
        dt_1 = DateTime()
        dt_2 = DateTime(second=800)
        self.assertNotEqual(dt_1, dt_2)

    # -------------------------------------------------------------------------

    def test_bad_datetime_to_dict(self):
        with self.assertRaises(TypeError):
            dd = DateTime.datetime_to_dict(1)

    def test_good_datetime_to_dict(self):
        dd_1 = DateTime.datetime_to_dict(dtime.now())
        dd_2 = self.__datetime_to_dict(dtime.now())
        self.assertEqual(dd_1, dd_2)

    # -------------------------------------------------------------------------

    def test_get_datetime(self):
        dt_1 = DateTime()
        dd_2 = self.__datetime_to_dict(dtime.now())
        dd_1 = dt_1.get_datetime()
        self.assertEqual(dd_1, dd_2)


    def test_get_strdatetime(self):
        d_1 = DateTime().__str__()
        dt = dtime.now()
        d_2 = f"{dt.year}/{dt.month}/{dt.day} {dt.hour}:{dt.minute}:{dt.second}"
        self.assertEqual(d_1, d_2)


    def test_get_date(self):
        d_1 = DateTime().get_date()
        dt = dtime.now()
        d_2 = {"year": dt.year, "month": dt.month, "day": dt.day}
        self.assertEqual(d_1, d_2)


    def test_get_strdate(self):
        d_1 = DateTime().get_strdate()
        dt = dtime.now()
        d_2 = f"{dt.year}/{dt.month}/{dt.day}"
        self.assertEqual(d_1, d_2)


    def test_get_time(self):
        t_1 = DateTime().get_time()
        dt = dtime.now()
        t_2 = {"hour": dt.hour, "minute": dt.minute, "second": dt.second}
        self.assertEqual(t_1, t_2)


    def test_get_strtime(self):
        t_1 = DateTime().get_strtime()
        dt = dtime.now()
        t_2 = f"{dt.hour}:{dt.minute}:{dt.second}"
        self.assertEqual(t_1, t_2)

    # -------------------------------------------------------------------------

    def test_get_year(self):
        y_1 = dtime.now().year
        y_2 = DateTime().get_year()
        self.assertEqual(y_1, y_2)


    def test_get_month(self):
        m_1 = dtime.now().month
        m_2 = DateTime().get_month()
        self.assertEqual(m_1, m_2)


    def test_get_day(self):
        d_1 = dtime.now().day
        d_2 = DateTime().get_day()
        self.assertEqual(d_1, d_2)


    def test_get_hour(self):
        h_1 = dtime.now().hour
        h_2 = DateTime().get_hour()
        self.assertEqual(h_1, h_2)


    def test_get_minute(self):
        h_1 = dtime.now().minute
        h_2 = DateTime().get_minute()
        self.assertEqual(h_1, h_2)


    def test_get_second(self):
        h_1 = dtime.now().second
        h_2 = DateTime().get_second()
        self.assertEqual(h_1, h_2)
