#pragma once
#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

// Template instance화는 총 2번의 과정을 거침.
// (1) 컴파일러가 템플릿 코드를 통해 구체적인 객체 코드 생성.
// (2) 생성한 코드를 이용해 Instance 생성.

template<typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T min(const T& a, const T& b)
{
	return (a < b ? a : b);
}

template<typename T>
T max(const T& a, const T& b)
{
	return (a > b ? a : b);
}
#endif // Template.hpp
