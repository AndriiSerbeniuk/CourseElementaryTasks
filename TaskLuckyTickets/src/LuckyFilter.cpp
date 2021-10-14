#include "LuckyFilter.hpp"

LuckyFilter::LuckyFilter(const std::vector<Ticket>& tickets, 
    bool (*predicate)(const Ticket&)) 
    : m_tickets(tickets), m_predicate(predicate) 
{}

LuckyFilter::LuckyIterator LuckyFilter::begin()
{
    return LuckyIterator(m_tickets.cbegin(), m_tickets.cend(), m_predicate);
}

LuckyFilter::LuckyIterator LuckyFilter::end()
{
    auto end_iter = m_tickets.cend();
    return LuckyIterator(end_iter, end_iter, nullptr);
}
