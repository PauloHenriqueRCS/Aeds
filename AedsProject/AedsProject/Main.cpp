#include "stdafx.h"

using namespace std;

//bool chainBalance(Battery * battery, string *chain)
//{
//	if (chain->find('{') || chain->find('}'))
//		keys(battery, chain);
//	if (chain->find('[') || chain->find(']'))
//		brackets(battery, chain);
//	if (chain->find('(') || chain->find(')'))
//		parentheses(battery, chain);
//
//	return battery->isEmpty();
//}
//
//void brackets(Battery * battery, string *chain) {
//	for (size_t i = 0; i < chain->length(); i++)
//	{
//		switch (chain->at(i))
//		{
//		case '[':
//			battery->stack(chain->at(i));
//			break;
//		case ']':
//			if (battery->top->element == '[')
//				battery->unpack();
//			break;
//		default:
//			break;
//		}
//	}
//}
//
//void keys(Battery * battery, string *chain) {
//	for (size_t i = 0; i < chain->length(); i++)
//	{
//		switch (chain->at(i))
//		{
//		case '{':
//			battery->stack(chain->at(i));
//			break;
//		case '}':
//			if (battery->top->element == '{')
//				battery->unpack();
//			break;
//		default:
//			break;
//		}
//	}
//}
//
//void parentheses(Battery * battery, string *chain) {
//	for (size_t i = 0; i < chain->length(); i++)
//	{
//		switch (chain->at(i))
//		{
//		case '(':
//			battery->stack(chain->at(i));
//			break;
//		case ')':
//			if (battery->top->element == '(')
//				battery->unpack();
//			break;
//		default:
//			break;
//		}
//	}
//}

int main()
{
	Battery * battery;
	battery = new Battery();
	battery->init();

	string exp = "E90E15E30+-C";

	for (size_t i = 0; i < exp.length(); i++)
		battery->stack(exp.at(i));
	battery->calculator();

	system("pause");
	return EXIT_SUCCESS;
}
