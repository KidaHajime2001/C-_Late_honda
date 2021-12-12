#pragma once
#include"pch.h"

#include"Component.h"
class Component;
using namespace std;
class GameObjectBase
{
public:
	//コンストラクタ
	GameObjectBase();
	//デストラクタ
	~GameObjectBase();
	

	void Update();
	void Draw();



	/// <summary>
	/// 指定したクラスをオブジェクトから取得する
	/// </summary>
	/// <typeparam name="T">
	/// 取得したいコンポーネントを指定する
	/// </typeparam>
	/// <returns>
	/// 取得したいコンポーネントを返す
	/// アタッチされていなければnullptrを返す
	/// </returns>
	template<class T>
	T* GetConponent()
	{
		//アタッチされているコンポーネントのリストから総当たりでcastする
		for (auto com : componentList)
		{
			T* buff = dynamic_cast<T*>(com);

			//castが成功した場合は戻り値でかえす
			if (buff != nullptr)
			{

				return buff;
			}

			//castが成功しない＝コンポーネントが存在しないのでnullptrをかえす
			return nullptr;
		}
	};


	/// <summary>
	/// GameObjectBaseにコンポーネントを追加する
	/// </summary>
	/// <typeparam name="T">
	/// 追加するコンポーネントの指定
	/// </typeparam>
	/// <returns>
	/// 追加したコンポーネントのポインタを返す
	/// コンポーネントを追加したスコープで編集しやすくなる
	/// </returns>
	template<class T>
	T* AddComponent()
	{

		T* buff = new T();
		buff->Parent = this;
		componentList.push_back(buff);
		buff->Start();
		return buff;

	};

private:
	//GameObjectにアタッチされているコンポーネントのリスト
	list<Component*> componentList;
};

