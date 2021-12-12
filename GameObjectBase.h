#pragma once
#include"pch.h"

#include"Component.h"
class Component;
using namespace std;
class GameObjectBase
{
public:
	//�R���X�g���N�^
	GameObjectBase();
	//�f�X�g���N�^
	~GameObjectBase();
	

	void Update();
	void Draw();



	/// <summary>
	/// �w�肵���N���X���I�u�W�F�N�g����擾����
	/// </summary>
	/// <typeparam name="T">
	/// �擾�������R���|�[�l���g���w�肷��
	/// </typeparam>
	/// <returns>
	/// �擾�������R���|�[�l���g��Ԃ�
	/// �A�^�b�`����Ă��Ȃ����nullptr��Ԃ�
	/// </returns>
	template<class T>
	T* GetConponent()
	{
		//�A�^�b�`����Ă���R���|�[�l���g�̃��X�g���瑍�������cast����
		for (auto com : componentList)
		{
			T* buff = dynamic_cast<T*>(com);

			//cast�����������ꍇ�͖߂�l�ł�����
			if (buff != nullptr)
			{

				return buff;
			}

			//cast���������Ȃ����R���|�[�l���g�����݂��Ȃ��̂�nullptr��������
			return nullptr;
		}
	};


	/// <summary>
	/// GameObjectBase�ɃR���|�[�l���g��ǉ�����
	/// </summary>
	/// <typeparam name="T">
	/// �ǉ�����R���|�[�l���g�̎w��
	/// </typeparam>
	/// <returns>
	/// �ǉ������R���|�[�l���g�̃|�C���^��Ԃ�
	/// �R���|�[�l���g��ǉ������X�R�[�v�ŕҏW���₷���Ȃ�
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
	//GameObject�ɃA�^�b�`����Ă���R���|�[�l���g�̃��X�g
	list<Component*> componentList;
};

