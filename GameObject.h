#pragma once
#include"pch.h"
#include"Component.h"
#include"DblBuffer.h"
class Object
{
public:
	Object() {}
	~Object() {
		for (auto com : ComponentList)
			delete com;
	}
	list<Component*> ComponentList;
	void Update()
	{
		auto buff = ComponentList;
		for (auto com : buff)
			com->Update();
	}
	void Draw(DblBuffer& db)
	{
		for (auto com : ComponentList)
			com->Draw(db);
	}
	//オブジェクトが持っているコンポーネントを取得
	template<class T>
	T* GetComponent()
	{
		for (auto com : ComponentList) {
			T* buff = dynamic_cast<T*>(com);
			if (buff != nullptr)
				return buff;
		}
		return nullptr;
	}
	//オブジェクトが持っているコンポーネントを追加
	template<class T>
	T* AddComponent()
	{
		T* buff = new T();
		buff->Parent = this;
		ComponentList.push_back(buff);
		buff->Start();
		return buff;
	}
};