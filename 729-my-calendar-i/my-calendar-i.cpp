class MyCalendar {
private:
    set<pair<int, int>> events;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto existingEventIterator = events.upper_bound({start, end});
        if (existingEventIterator != events.end() &&
            existingEventIterator->second < end) {
            return false;
        } else {
            events.insert({end, start});
            return true;
        }
    }
};
