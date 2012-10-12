#include <LuaPlus.h>
#include <iostream>
#include <string>

/*
extern "C"
{
	#include <src/lua.h>
	#include <src/lauxlib.h>
	#include <src/lualib.h>
}
*/

using namespace std;
using namespace LuaPlus;

int TestFunc(LuaState* state)
{
	LuaStack args(state);
	
	std::string strName = args[1].GetString();
	
	cout<<"TestFunc Name: "<<strName<<endl;

	state->PushInteger(1);
	
	return 1;
}

int main(int argc, char** argv)
{
	LuaState* pstate = LuaState::Create(true);	

	pstate->GetGlobals().Register("TestFunc", TestFunc);	

	const char* szCmd = "TestFunc('hahhahhahh');";
	pstate->DoString(szCmd);

	LuaState::Destroy(pstate);
	return 0;
}
