//#include <iostream>
//#include <memory>
//using namespace std;
//
//int main() {
//	unique_ptr<int> up1(new int(3));
//	unique_ptr<int> up2 = make_unique<int>(4);
//	unique_ptr<int> up3 = unique_ptr<int>(new int(5));
//
//	shared_ptr<int> sp1(new int(13));
//	shared_ptr<int> sp2 = make_shared<int>(14);
//	shared_ptr<int> sp3 = shared_ptr<int>(new int(15));
//	shared_ptr<int> sp4(sp1);
//	cout << sp1 << endl << sp2 << endl << sp3 << endl << sp4 << endl;
//	cout << "===============================" << endl;
//	int* p = new int(20);
//	shared_ptr<int> sp5(p);
//	shared_ptr<int> sp6 = shared_ptr<int>(sp5);
//	cout << sp5.use_count() << endl << sp6.use_count() << endl;
//
//	return 0;
//}


#include <iostream>
using namespace std;

template <class T>
class SharedPtr
{
public:
	SharedPtr() {
		thePtr = NULL;
		theUseCount = NULL;
	}
	SharedPtr(T* tP) {
		thePtr = tP;
		if (theUseCount == NULL) {
			theUseCount = new int(0);
		}
		(*theUseCount)++;
	}
	SharedPtr(const SharedPtr<T>& sp) {
		if (thePtr != NULL) {
			(*theUseCount)--;
			if ((*theUseCount) == 0) {
				delete thePtr;
				delete theUseCount;
			}
			thePtr = NULL;
			theUseCount = NULL;
		}
		thePtr = sp.thePtr;
		theUseCount = sp.theUseCount;
		(*theUseCount)++;
	}

	~SharedPtr() {
		(*theUseCount)--;
		if ((*theUseCount) == 0) {
			delete thePtr;
			delete theUseCount;
		}
		thePtr = NULL;
		theUseCount = NULL;
	}
	SharedPtr<T>& operator=(const SharedPtr<T>& sp) {
		if (thePtr != NULL) {
			(*theUseCount)--;
			if ((*theUseCount) == 0) {
				delete thePtr;
				delete theUseCount;
			}
		}
		thePtr = sp.thePtr;
		theUseCount = sp.theUseCount;
		(*theUseCount)++;
		return *this;
	}
	T& operator*() {
		return *thePtr;
	}
	T* operator->() {
		return thePtr;
	}

private:
	T* thePtr;
	int* theUseCount;
};

void TestSharpedPtr()
{
	SharedPtr<int> ap1(new int(10));
	SharedPtr<int> ap2(new int(20));
	SharedPtr<int> ap3(ap1);
	SharedPtr<int> ap4;
	ap4 = ap1;
	*ap1 = 1;
	*ap2 = 2;
	*ap3 = 3;
	*ap4 = 4;
}
int main()
{
	TestSharpedPtr();
	return 0;
}