#include "HumanA.hpp"
#include "HumanB.hpp"

/*  NOTE:  What is const reference&?
https://stackoverflow.com/questions/2627166/what-is-the-difference-between-a-const-reference-and-normal-parameter
*/

int main()
{
	// WARN:  이 예제는 club의 타입이 바뀌었을 때 모든 human에게 반영된다는 것을
	// main소스코드 상에서 알아채기 어렵다.
	// ! Human이 많아 질 경우 대형사고 날수도 있지 않을까?
	// 따x. --> 다른 Human class는 바뀌면 안되는 경우.
	// 따라서 첫째, weapon 속성은 human들이 공유하지 않도록 value로 갖고 있던가
	// 아니면 둘째, weapon을 포인터로 받아서 함수 호출자가 아 주소를 받네? 그럼 바뀌겠네?
	// 를 알 수 있게 하던가....

	// NOTE:  [1] 주소를 쓸거라면, HumanClass의 weapon을 const*로 바꾸고,
	// HumanA bob("Bob", &club); 처럼 애초에 포인터를 받도록 한다. (가독성 향상)
	// 속성을 변경해야 할 경우에만 const_cast로 임시 해제 후 속성을 바꾼다.

	// NOTE:  [2] weapon class를 상속받는 club class를 만든다.


	// NOTE:  [3] (bad) 주소를 쓰지 않고  HumanA의 멤버함수에 setWeaponType() 메서드를 이용한다.
	// --> ex) bob.setGlobalWeaponType("some other type of club");


	// NOTE:  [4] pointer 혹은 reference를 반환하는
	// &Weapon getWeaponRef() 메소드를 구현한다.
	// --> ex) bob.getWeaponRef().setType("some other type of club");

	{
		Weapon club = Weapon("crude spiked club");
		//  TODO:  HumanA bob("bob", &club);
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club"); // WARN:  every weapon data will change.
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		//  TODO:  jim.setWeapon(&club);
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");  // WARN:  every weapon data will change.
		jim.attack();
	}

	return 0;
}
