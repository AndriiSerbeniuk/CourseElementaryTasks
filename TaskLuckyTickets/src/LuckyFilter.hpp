#pragma once
#include <vector>
#include "Ticket.hpp"

// Wrapper for a vector of tickets that iterates only on the tickets that suit the given predicate
class LuckyFilter
{
public:
    // Const iterator on a vector of tickets that skips tickets that don't suit the predicate
    struct LuckyIterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = const Ticket;
        using pointer = const Ticket*;
        using reference = const Ticket&;

        LuckyIterator(
            std::vector<Ticket>::const_iterator begin, 
            std::vector<Ticket>::const_iterator end, 
            bool (*predicate)(const Ticket&));

        std::vector<Ticket>::const_iterator next() const;

        reference operator*() const;
        pointer operator->() const;
        
        LuckyIterator& operator++();
        LuckyIterator operator++(int);

        friend bool operator==(const LuckyIterator& lhs, const LuckyIterator& rhs);
        friend bool operator!=(const LuckyIterator& lhs, const LuckyIterator& rhs);
        
    private:
        std::vector<Ticket>::const_iterator m_begin;
        std::vector<Ticket>::const_iterator m_end;
        bool (*m_predicate)(const Ticket&);
    };

    LuckyFilter(const std::vector<Ticket>& tickets, bool (*predicate)(const Ticket&));

    LuckyIterator begin();
    LuckyIterator end();

private:
    const std::vector<Ticket>& m_tickets;
    bool (*m_predicate)(const Ticket&);

};