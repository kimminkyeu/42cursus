#include "Span.hpp"

Span::Span()
	:_maximumInts(0)
{}

Span::~Span()
{}

Span::Span(const int& nmemb)
	:_maximumInts(nmemb)
{}

Span::Span(const Span& span)
	:_maximumInts(span._maximumInts)
{
	(*this) = span;
}

Span& Span::operator= (const Span& span)
{
	_maximumInts = span._maximumInts;
	_vec = span._vec;
	return (*this);
}

void Span::addNumber(const int& integer)
{
	if (_maximumInts <= _vec.size())
	{
		throw(std::runtime_error("[Exception] elements are full: " + std::to_string(_vec.size())));
	}
	else
	{
		_vec.push_back(integer);
	}
}

int	Span::shortestSpan()
{
	if (_vec.size() <= 1)
	{
		throw(std::runtime_error("[Exception] elements are full: " + std::to_string(_vec.size())));
	}
	else
	{
		std::sort(_vec.begin(), _vec.end());
		int sp = std::numeric_limits<int>::max();
		for (int i=1; i<_vec.size(); i++)
		{
			int diff = _vec[i] - _vec[i - 1];
			if (sp > diff) sp = diff; }
		return sp;
	}
}

int Span::longestSpan()
{
	if (_vec.size() <= 1)
	{
		throw(std::runtime_error("elements are full: " + std::to_string(_vec.size())));
	}
	else
	{
		std::sort(_vec.begin(), _vec.end());
		return (*(_vec.end() - 1) - *_vec.begin());
	}
}

int Span::operator[] (const int& index) const
{
	if (index < 0 || index > _vec.size() - 1)
		throw(std::runtime_error("exception: index out of range"));
	else
	{
		return (this->_vec[index]);
	}
}

static void setRandomValue(int& a)
{
	a = rand();
}

void Span::fillSpanRandom()
{
	srand(time(NULL));
	// set it's max
	_vec.resize(_maximumInts);
	std::for_each(_vec.begin(), _vec.end(), setRandomValue);
}

int Span::size() const
{
	return (this->_vec.size());
}

std::ostream& operator<< (std::ostream& out, const Span& span)
{
	for (int i=0; i<span.size(); i++)
	{
		out << span[i] << " ";
	}
	return (out);
}
