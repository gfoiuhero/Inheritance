#include<iostream>
#include<string>
class Human

{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name() const
	{
		return last_name;
	}
	const std::string& get_first_name() const
	{

		return first_name;
	}
	const unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;

	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	////   CONSTRUCTORS

	Human(const std::string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		std::cout << "Hconstructor:\t" << this << std::endl;
	}
	~Human()
	{
		std::cout << "Hdestructor:\t" << this << std::endl;
	}
	void print()const
	{
		std::cout << last_name << "\t" << first_name << "\t" << age << std::endl;
	}
};
class Student :public Human
{
	std::string spec;
	std::string group;
	unsigned int rating;
	unsigned int attendence;
public:
	const std::string& get_specialty() const
	{
		return spec;
	}
	const std::string& get_group() const
	{
		return group;
	}
	unsigned int get_rating() const
	{
		return rating;
	}
	unsigned int get_attendence()const
	{
		return attendence;
	}
	void set_specialty(const std::string& spec)
	{
		this->spec = spec;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(unsigned int rating)
	{
		this->rating = rating <= 100 ? rating : 0;
	}
	void set_attendence(unsigned int attendence)
	{
		this->attendence = attendence <= 100 ? attendence : 100;
	}

	//			Constructor:
	Student(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string& group, unsigned int rating, unsigned int attendence 
	) :Human(last_name, first_name, age)
	{
		set_specialty(spec);
		set_group(group);
		set_rating(rating);
		set_attendence(attendence);
		std::cout << "Sconstructor:\t" << this << std::endl;
	}
	~Student()
	{
		std::cout << "Hdestructor:\t" << this << std::endl;
	}
	void print()const
	{
		Human::print();
		std::cout << spec << "\t" << group << ", yспеваемость " << rating << "%, посещаемость " << attendence << "%\n";
	}
};
class Teacher :public Human
{
	std::string subject;
	unsigned int experience;
	unsigned int evil;

public:
	const std::string& get_subject()const
	{
		return subject;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	unsigned int get_evil()const
	{
		return evil;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;

	}
	void set_evil(unsigned int evil)
	{
		this->evil = evil;
	}

	//			Constructor:
	Teacher
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& subject, unsigned int experience, unsigned int evil
	) :Human(last_name, first_name, age)
	{
		set_subject(subject);
		set_experience(experience);
		set_evil(evil);
		std::cout << "Tconstructor:\t" << this << std::endl;
	}
	~Teacher()
	{
		std::cout << "TDestructor:\t" << this << std::endl;
	}
	void print()
	{
		Human::print();
		std::cout << "Предмет: " << subject << ", Количество груп " << experience << ", уровень злости" << evil << std::endl;
	}
};
class Graduate : public Student
{
	std::string topic_graduate;
	std::string curator;
	unsigned int number_of_pages;

public:
	const std::string& get_topic_graduate() const
	{
		return topic_graduate;
	}
	const std::string& get_curator() const
	{
		return curator;
	}
	unsigned int get_number_of_pages() const
	{
		return number_of_pages;
	}
	void set_topic_graduate(const std::string& topic_graduate)
	{
		this->topic_graduate = topic_graduate;
	}
	void set_curator(const std::string& curator)
	{
		this->curator = curator;
	}
	void set_number_of_pages(unsigned int number_of_pages)
	{
		this->number_of_pages = number_of_pages;

	}
	//			CONSTRUCTOR:
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string& group, unsigned int rating, unsigned int attendence,
		const std::string& topic_graduate, const std::string& curator, unsigned int number_of_pages
	) :Student(last_name, first_name, age, spec, group, rating, attendence)
	{
		set_topic_graduate(topic_graduate);
		set_number_of_pages(number_of_pages);
		set_curator(curator);
		std::cout << "Gconstructor:\t" << this << std::endl;
	}
	~Graduate()
	{
		std::cout << "GDestructor:\t" << this << std::endl;
	}
	void print()
	{
		Student::print();
		std::cout << "Тема: " << topic_graduate << "Кличка куратора: " << curator << ", Количество страниц " << number_of_pages << std::endl;
	}
};



void main()
{
	setlocale(LC_ALL, "");
	Human Vasya("Жернов", "Ярик", 22);
	Vasya.print();
	Student student("Alax", "Akbar", 13, "Dizain", "ST DV 37", 10,13);
	student.print();
	Teacher("Einstein", "Albert", 141, "Astronomi", 5, 5).print();
	Graduate("\nAlax", "Akbar", 13, "Dizain", "ST DV 37", 90, 30, " Создание взрывчатки в домашних условиях, ", "Подрывник", 666).print();

}
