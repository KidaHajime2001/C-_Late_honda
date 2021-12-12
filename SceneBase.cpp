#include"pch.h"
#include "SceneBase.h"

SceneBase::SceneBase()
{
}

SceneBase::~SceneBase()
{
	for (auto obj : objects_List)
		delete obj;
	objects_List.clear();

}

SceneBase* SceneBase::Update()
{
	return nullptr;
}

void SceneBase::Draw()
{
}
