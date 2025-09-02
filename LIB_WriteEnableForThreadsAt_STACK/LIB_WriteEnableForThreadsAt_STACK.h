#ifdef LIBWRITEENABLESTACK_EXPORTS
#define LIBWRITEENABLEATSTACK_API __declspec(dllexport)
#else
#define LIBWRITEENABLEATSTACK_API __declspec(dllimport)
#endif

namespace Avril_FSD
{
	class LIBWRITEENABLEATSTACK_API LIB_WriteEnableForThreadsAt_STACK {
	public:
		LIB_WriteEnableForThreadsAt_STACK();
		static void* Initialise_WriteEnable();
		void Write_End(class WriteEnable_STACK_Framework* obj, unsigned char coreId);
		void Write_Start(class WriteEnable_STACK_Framework* obj, unsigned char coreId);

	private:
		static class WriteEnable_STACK_Framework* Get_Framework_WriteEnable();
		static void Set_writeEnable(class Avril_FSD::WriteEnable_STACK_Framework* writeEnable);
	};
}