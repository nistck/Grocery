// dllmain.h: 模块类的声明。

class CGroceryHandlersModule : public ATL::CAtlDllModuleT<CGroceryHandlersModule>
{
public :
	DECLARE_LIBID(LIBID_GroceryHandlersLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_GROCERYHANDLERS, "{cbd7fe7e-557d-4d71-9454-cc1549d6ff76}")
};

extern class CGroceryHandlersModule _AtlModule;
