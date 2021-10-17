#pragma once
#include <vector>
#include "Ticket.hpp"
#include "LuckyIterator.hpp"

// Wrapper for a container of Tickets
// Iterates only on the Tickets that suit the given predicate
template<class iter>
class LuckyFilter
{
public:
    LuckyFilter(iter start, iter end, bool (*predicate)(const Ticket&))
        : m_start(start), m_end(end), m_predicate(predicate) 
    {}

    LuckyIterator<iter> begin()
    {
        return LuckyIterator<iter>(m_start, m_end, m_predicate);
    }

    LuckyIterator<iter> end()
    {
        return LuckyIterator<iter>(m_end, m_end, nullptr);
    }

private:
    iter m_start;
    iter m_end;
    bool (*m_predicate)(const Ticket&);
};
