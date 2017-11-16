#pragma once
#include "../stdafx.h"

class NameChecker
{
public:
	NameChecker(): m_biggerName(""), m_nameCount(0) {}
	~NameChecker() {}

	void operator()(string name)
	{
		if (m_biggerName.size() < name.size())
			m_biggerName = name;

		m_nameCount++;
	}

	const string& getBiggerName() const
	{
		return m_biggerName;
	}

	int getNameCount() const
	{
		return m_nameCount;
	}

private:
	string m_biggerName;
	int m_nameCount;
};