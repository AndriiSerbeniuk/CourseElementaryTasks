#include "LuckyFilter.hpp"

LuckyFilter::LuckyIterator::LuckyIterator(
    std::vector<Ticket>::const_iterator begin, 
    std::vector<Ticket>::const_iterator end, 
    bool (*predicate)(const Ticket&))
    : m_begin(begin), m_end(end), m_predicate(predicate)
{
    // Initial begin value may not suit the predicate
    if (m_begin != m_end && !m_predicate(*m_begin))
    {
        m_begin = next();
    }
}

std::vector<Ticket>::const_iterator LuckyFilter::LuckyIterator::next() const
{
    std::vector<Ticket>::const_iterator temp_begin = m_begin;

    // Iterate through tickets until a lucky one is found
    do
    {
        ++temp_begin;
    } while (temp_begin != m_end && !m_predicate(*temp_begin));

    return temp_begin;
}


LuckyFilter::LuckyIterator::reference LuckyFilter::LuckyIterator::operator*() const
{
    return *m_begin;
}

LuckyFilter::LuckyIterator::pointer LuckyFilter::LuckyIterator::operator->() const
{
    return &(*m_begin);
}

// Prefix increment
LuckyFilter::LuckyIterator& LuckyFilter::LuckyIterator::operator++()
{

    m_begin = next();
    return *this;
}

// Postfix increment
LuckyFilter::LuckyIterator LuckyFilter::LuckyIterator::operator++(int)
{
    LuckyIterator temp = *this;
    ++(*this);
    return temp;
}

bool operator==(const LuckyFilter::LuckyIterator& lhs, 
    const LuckyFilter::LuckyIterator& rhs)
{
    return lhs.m_begin == rhs.m_begin;
}

bool operator!=(const LuckyFilter::LuckyIterator& lhs, 
    const LuckyFilter::LuckyIterator& rhs)
{
    return lhs.m_begin != rhs.m_begin;
}
