#include <iostream>
#include <string>

template<class K,class V>
struct Map
{
	K keys[100];
	V values[100];
	int size;
};

template<class K,class V>
void Initialize(Map<K,V>& map)
{
	map.size = 0;
}

template<class K,class V>
void Put(Map<K,V>&,const K& key,const V& value)
{
	return;
}

template<class K,class V>
V& Get(Map<K,V>&,const K& key)
{
	throw "Key Does Not Exists";
}

template<class K,class V>
bool Contains(Map<K,V>&,const K& key)
{
	return false;
}

template<class K,class V>
void Remove(Map<K,V>&,const K& key)
{
	return;
}

int main()
{
	return 0;
}
