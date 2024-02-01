#include <iostream>



//static - относительно элементов класса. 

// static для класса

class SequencesGenerator {  //генератор последовательности
public:
	void M00()const {}

	static void M01(){}

	// позволяет создавать вызовы метода без создания объекта класса
	static int NextNum()
	{
		//M00();  нет доступа так как нет указателя на себя
		M01();		
		return n++;
	}
	// в статическом методе нельзя обращаться к нестатическим элементам класса

private:
	static int n; // переместили переменную в глобальную память программы
	//неконстантные статические поля нельзя использовать без инициализации и их определение должно происходить вне класса

	// константные статические поля допустимо определять в теле класса
	//static const int n{ 10 };
};

//определение статических полей всегда выносим в файл кода
int SequencesGenerator::n{ 3};

// static для функуции - такая функция будет запрещена для вызова в других кодовых файлах программы
 static int NumSequence()   
{
	static int n{}; //static - переместит переменную в глобальную память программы 
	return n++;
}

 void CatDemo();



int main() {
	setlocale(LC_ALL, "ru");

	for (size_t i = 0; i < 6; i++)
	{
		std::cout << NumSequence() << '\n';
	}


	//SequencesGenerator obj;
	for (size_t i = 0; i < 6; i++)
	{
		//std::cout << obj.NextNum() << '\n';  // если не прописан static у метода
		std::cout << SequencesGenerator::NextNum() << '\n'; // если добавить к функции статик, позволяет ипользовать метод без создания объекта класса
	}	

	CatDemo();



	return 0;
}


// нужно создать класс который без создания объектов могбы сообщать свое название \
данный класс сделать н апримере животного (кошка) \
включить в класс методы которые бы пользовались сттическим методом для формирования сообщений на экране


class Cat {
public:
	static void Name()
	{
		std::cout << name;
	}
	void Say()const
	{
		Name();
		std::cout << " Maf\n";
	}
	void Feed(std::string food)const
	{
		Name();
		std::cout << " eat: " << food << '\n';
	}
private:
	static std::string name; //объявление 

};

std::string Cat::name{ "Cat" }; // определение и установка начального значения

void CatDemo() {
	std::cout << "We have a ";
	Cat::Name();
	std::cout << '\n';
	Cat cat;
	cat.Feed("mice");
	cat.Say();
}