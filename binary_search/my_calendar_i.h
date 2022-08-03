/*
should be straight forward enough but easy to miss some details
*/
class MyCalendar {
    struct Interval {
        int start = 0;
        int end = 0;
    };
    std::vector<Interval> calendar;

  public:
    MyCalendar() {}

    bool book(int start, int end) {
        Interval interval{start, end};
        auto it = std::upper_bound(calendar.begin(), calendar.end(), interval,
                                   [](const auto& itv1, const auto& itv2) {
                                       return itv1.start < itv2.start;
                                   });
        if (it != calendar.end() && it->start < interval.end) {
            return false;
        }

        if (it != calendar.begin() && std::prev(it)->end > interval.start) {
            return false;
        }

        calendar.emplace(it, std::move(interval));
        return true;
    }
};
