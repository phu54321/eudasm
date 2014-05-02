#include "..\type\type.h"
#include <iostream>

void test_type() {
	CTypePtr ptr1(new CType_Void);
	CTypePtr ptr2(new CType_Ref(ptr1));
	CTypePtr ptr3(new CType_Array(ptr2,30));
	std::cout << *ptr3 << ' ' << ptr3->GetHash() << std::endl;

	CTypePtr ptr4(new CType_Void);
	CTypePtr ptr5(new CType_Ref(ptr4));
	CTypePtr ptr6(new CType_Array(ptr5,30));
	std::cout << *ptr6 << ' ' << ptr6->GetHash() << std::endl;

	std::vector<CTypePtr> typelist;
	typelist.push_back(ptr2);
	typelist.push_back(ptr3);
	typelist.push_back(ptr5);
	typelist.push_back(ptr6);
	CTypePtr ptr7(new CType_Struct(typelist));
	std::cout << *ptr7 << std::endl;
}
