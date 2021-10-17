#pragma once
#include "Ticket.hpp"

// Iterator on a container of Tickets
// Skips tickets that don't suit the predicate
template<class iter>
struct LuckyIterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = const Ticket;
    using pointer = const Ticket*;
    using reference = const Ticket&;

    LuckyIterator(
        iter begin, 
        iter end, 
        bool (*predicate)(const Ticket&))
        : m_begin(begin), m_end(end), m_predicate(predicate)
    {
        // Initial begin value may not suit the predicate
        if (m_begin != m_end && !m_predicate(*m_begin))
        {
            m_begin = next();
        }
    }

    iter next() const
    {
        iter temp_begin = m_begin;

        // Iterate through tickets until a lucky one is found
        do
        {
            ++temp_begin;
        } while (temp_begin != m_end && !m_predicate(*temp_begin));

        return temp_begin;
    }

    reference operator*() const
    {
        return *m_begin;
    }

    pointer operator->() const
    {
        return &(*m_begin);
    }
    
    LuckyIterator<iter>& operator++()
    {
        m_begin = next();
        return *this;
    }

    LuckyIterator<iter> operator++(int)
    {
        LuckyIterator temp = *this;
        ++(*this);

        return temp;
    }

    bool operator==(const LuckyIterator<iter>& rhs)
    {
        return m_begin == rhs.m_begin;
    }

    bool operator!=(const LuckyIterator<iter>& rhs)
    {
        return m_begin != rhs.m_begin;
    }
    
private:
    iter m_begin;
    iter m_end;
    bool (*m_predicate)(const Ticket&);
};
