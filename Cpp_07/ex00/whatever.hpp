#pragma once

template<typename T>
void swap(T &a, T &b)
{
	T aux = a;
	a=b;
	b=aux;
}

template<typename T>
T &min(T &a, T &b){return (a<b? a:b);}

template<typename T>
T &max(T &a, T &b){return (a>b? a:b);}