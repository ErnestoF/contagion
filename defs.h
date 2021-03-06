#pragma once

#include <list>
#include <set>
#include <vector>
#include <cstdint>
#include <QtGlobal>
enum State
{
    NOT_REQUESTABLE, // 0
    REQUESTABLE, // 1
    ILL, // 2
    NOT_ILL // 3
};


namespace constants
{
    constexpr uint8_t NUM_DAYS = 10;
    constexpr uint8_t NUM_HUMANS = 10;
}
class Human
{
public:
    explicit Human(uint8_t h)
        : m_id(h)
    {
        Q_ASSERT(0 <= h && h < constants::NUM_HUMANS);
    }
    operator uint8_t() const
    {
        return m_id;
    }
    private:
        uint8_t m_id;
};
class Day
{
public:
    explicit Day(uint8_t d)
        : m_id(d)
    {
        Q_ASSERT(0 <= d && d < constants::NUM_DAYS);
    }
    operator uint8_t() const
    {
        return m_id;
    }
private:
        uint8_t m_id;
};

class Meeting
{
public:
    Meeting(Day d, std::set<Human> participants);
    Day day() const;
    std::set<Human> participants() const;
    bool operator==(Meeting const& other) const;
private:
    Day m_day;
    std::set<Human> m_humans;
};

namespace constants
{
    extern const std::array<Human, NUM_HUMANS> HUMANS;
    extern const std::array<Day, NUM_DAYS> DAYS;
}
typedef std::list<Meeting> meetings_t;
