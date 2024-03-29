#include<stdio.h>
#include<Windows.h>



used in function "GetDllBaseAddress";
typedef struct _LDR_DATA_TABLE_ENTRY {
	PVOID Reserved1[2];              // 0
	LIST_ENTRY InMemoryOrderLinks;   // 16
	PVOID Reserved2[2];              // 32
	PVOID DllBase;                   // 48
	PVOID EntryPoint;                // 56
	PVOID Reserved3;                 // 64
	UNICODE_STRING FullDllName;      // 72 
	UNICODE_STRING DllName;          // 88
	PVOID Reserved5[3];
	union {
		ULONG CheckSum;
		PVOID Reserved6;
	};
	ULONG TimeDateStamp;
} LDR_DATA_TABLE_ENTRY, * PLDR_DATA_TABLE_ENTRY;







void kernelCode() {

	KAPC_STATE state;
	KeStackAttachProcess(proc, &state);

	PPEB pPeb = (PPEB)PsGetProcessPeb(proc);
	if (!pPeb)
	{
		return 0;
	}
	PPEB_LDR_DATA pLdr = (PPEB_LDR_DATA)pPeb->Ldr;

	if (!pLdr)
	{
		KeUnstackDetachProcess(&state);
		return 1;
	}

	UNICODE_STRING name;

	for (PLIST_ENTRY list = (PLIST_ENTRY)pLdr->ModuleListLoadOrder.Flink;
		list != &pLdr->ModuleListLoadOrder; list = (PLIST_ENTRY)list->Flink)
	{
		PLDR_DATA_TABLE_ENTRY pEntry =
			CONTAINING_RECORD(list, LDR_DATA_TABLE_ENTRY, InLoadOrderModuleList);
		if (RtlCompareUnicodeString(&pEntry->BaseDllName, &module_name, TRUE) ==
			0) {
			ULONG64 baseAddr = (ULONG64)pEntry->DllBase;
			KeUnstackDetachProcess(&state);
			return baseAddr;
			//a2[v3] = a1[keyIndex] ^ a1[v3];
		//v3++;
		}
	}
	KeUnstackDetachProcess(&state);
}


 



void xor_algorithm(char* a1, char* a2, int keyIndex)
{
	__int64 result; // rax
	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[keyIndex] ^ a1[v3];
		v3++;
	} while (a2[v3 - 1]);

}

void sub_140008A14(char* a1, char* a2) {
	__int64 result; // rax
	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[5] ^ a1[v3];
		v3++;
		/*result = (unsigned __int8)a2[v3++];*/
	} while (a2[v3 - 1]);



}


void dotSysStr()
{
	char unk_140080738[50];


	char v1[8]; // [rsp+28h] [rbp-20h] BYREF

	v1[0] = 78;
	v1[1] = 19;
	v1[2] = 25;
	v1[3] = 19;
	v1[4] = 96;
	v1[5] = 96;
	sub_140008A14(v1, unk_140080738);


	printf("%s\n", unk_140080738); //.sys;

}

void sub_140001EAC(char* a1, char* a2) {
	__int64 result; // rax
	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[8] ^ a1[v3];
		v3++;
	} while (a2[v3 - 1]);

}

void sub_140008310()
{
	// 2 function

	char v1[9]; // [rsp+28h] [rbp-20h] BYREF
	//char v2[3]; // [rsp+2Eh] [rbp-1Ah] BYREF  (unused)
	char unk_140080730[50];
	v1[0] = 30;
	v1[1] = 31;
	v1[2] = 27;
	v1[3] = 3;
	v1[4] = 8;
	v1[5] = 25;

	memcpy(&v1[6], "_mm", 3);
	sub_140001EAC(v1, unk_140080730);
	printf("%s\n", unk_140080730); //zsrvnet2
}


//function2 in the main()
void sub_140005598(char* a1, char* a2)
{
	__int64 result; // rax
	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[29] ^ a1[v3];
		v3++;
	} while (a2[v3 - 1]);

}
void sub_140007F8C()
{
	char v1[60]; // [rsp+28h] [rbp-30h] BYREF
	char unk_140080860[60];

	v1[0] = 36;
	v1[1] = 11;
	v1[2] = 1;
	v1[3] = 11;
	v1[4] = 12;
	v1[5] = 29;
	v1[6] = 21;
	v1[7] = 10;
	v1[8] = 23;
	v1[9] = 23;
	v1[10] = 12;
	v1[11] = 36;
	v1[12] = 11;
	v1[13] = 1;
	v1[14] = 11;
	v1[15] = 12;
	v1[16] = 29;
	v1[17] = 21;
	v1[18] = 75;
	v1[19] = 74;
	v1[20] = 36;
	v1[21] = 28;
	v1[22] = 10;
	v1[23] = 17;
	v1[24] = 14;
	v1[25] = 29;
	v1[26] = 10;
	v1[27] = 11;
	v1[28] = 120;
	v1[29] = 120;
	sub_140005598(v1, unk_140080860);
	printf("%s\n", unk_140080860);

}


void __fastcall xor_algorithm_5(char* a1, char* a2)
{
	__int64 result; // rax
	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[29] ^ a1[v3];
		v3++;
	} while (a2[v3 - 1]);

}

void sub_140007EA8()
{
	char v1[32]; // [rsp+28h] [rbp-30h] BYREF
	char byte_140080748[50];
	v1[0] = 36;
	v1[1] = 11;
	v1[2] = 1;
	v1[3] = 11;
	v1[4] = 12;
	v1[5] = 29;
	v1[6] = 21;
	v1[7] = 10;
	v1[8] = 23;
	v1[9] = 23;
	v1[10] = 12;
	v1[11] = 36;
	v1[12] = 11;
	v1[13] = 1;
	v1[14] = 11;
	v1[15] = 12;
	v1[16] = 29;
	v1[17] = 21;
	v1[18] = 75;
	v1[19] = 74;
	v1[20] = 36;
	v1[21] = 28;
	v1[22] = 10;
	v1[23] = 17;
	v1[24] = 14;
	v1[25] = 29;
	v1[26] = 10;
	v1[27] = 11;
	v1[28] = 120;
	v1[29] = 120;
	xor_algorithm_5(v1, byte_140080748);
	printf("%s\n", byte_140080748);
}

void sub_1400020D4(char* a1, char* a2)
{
	__int64 result; // rax
	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[13] ^ a1[v3];
		v3++;
	} while (a2[v3 - 1]);

}

void sub_1400023F4()
{
	char v1[16]; // [rsp+28h] [rbp-20h] BYREF
	char unk_140080450[25];

	v1[0] = 50;
	v1[1] = 31;
	v1[2] = 43;
	v1[3] = 26;
	v1[4] = 13;
	v1[5] = 9;
	v1[6] = 28;
	v1[7] = 13;
	v1[8] = 46;
	v1[9] = 1;
	v1[10] = 4;
	v1[11] = 13;
	v1[12] = 104;
	v1[13] = 104;
	sub_1400020D4(v1, unk_140080450);
	printf("%s\n", unk_140080450);
}

void sub_140003B10()
{
	char v1[24]; // [rsp+28h] [rbp-30h] BYREF
	char unk_140080528[50];

	v1[0] = 40;
	v1[1] = 5;
	v1[2] = 35;
	v1[3] = 7;
	v1[4] = 23;
	v1[5] = 0;
	v1[6] = 11;
	v1[7] = 59;
	v1[8] = 28;
	v1[9] = 20;
	v1[10] = 29;
	v1[11] = 0;
	v1[12] = 31;
	v1[13] = 19;
	v1[14] = 6;
	v1[15] = 27;
	v1[16] = 29;
	v1[17] = 28;
	v1[18] = 52;
	v1[19] = 27;
	v1[20] = 30;
	v1[21] = 23;
	v1[22] = 114;
	v1[23] = 114;
	xor_algorithm(v1, unk_140080528, 23);
	printf("%s\n", unk_140080528);
}

// xor_algorithm(char* a1, char* a2, int keyIndex)
void sub_140001FC0(char* a1, char* a2)
{
	__int64 result; // rax
	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[21] ^ a1[v3];
		v3++;
	} while (a2[v3 - 1]);

}


void sub_1400012D0()
{
	char v1[24]; // [rsp+28h] [rbp-30h] BYREF
	char unk_140080388[50];
	v1[0] = 32;
	v1[1] = 3;
	v1[2] = 51;
	v1[3] = 2;
	v1[4] = 21;
	v1[5] = 17;
	v1[6] = 4;
	v1[7] = 21;
	v1[8] = 35;
	v1[9] = 9;
	v1[10] = 3;
	v1[11] = 4;
	v1[12] = 21;
	v1[13] = 29;
	v1[14] = 36;
	v1[15] = 24;
	v1[16] = 2;
	v1[17] = 21;
	v1[18] = 17;
	v1[19] = 20;
	v1[20] = 112;
	v1[21] = 112;
	sub_140001FC0(v1, unk_140080388);
	printf("%s\n", unk_140080388);
}



void sub_14000201C(char* a1, char* a2)
{

	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[24] ^ a1[v3];
		v3++;
	} while (a2[v3 - 1]);

}
void sub_140001000()
{
	char v1[32]; // [rsp+28h] [rbp-30h] BYREF
	char unk_1400803A8[50];
	v1[0] = 45;
	v1[1] = 14;
	v1[2] = 41;
	v1[3] = 24;
	v1[4] = 15;
	v1[5] = 16;
	v1[6] = 20;
	v1[7] = 19;
	v1[8] = 28;
	v1[9] = 9;
	v1[10] = 24;
	v1[11] = 46;
	v1[12] = 4;
	v1[13] = 14;
	v1[14] = 9;
	v1[15] = 24;
	v1[16] = 16;
	v1[17] = 41;
	v1[18] = 21;
	v1[19] = 15;
	v1[20] = 24;
	v1[21] = 28;
	v1[22] = 25;
	v1[23] = 125;
	v1[24] = 125;
	sub_14000201C(v1, unk_1400803A8);
	printf("%s\n", unk_1400803A8);
}


void sub_1400010C8()
{
	char v1[16]; // [rsp+28h] [rbp-20h] BYREF
	char  byte_1400803C8[40];
	v1[0] = 55;
	v1[1] = 26;
	v1[2] = 46;
	v1[3] = 1;
	v1[4] = 2;
	v1[5] = 30;
	v1[6] = 8;
	v1[7] = 109;
	v1[8] = 109;
	xor_algorithm(v1, byte_1400803C8, 8);

	printf("%s\n", byte_1400803C8);
}


//

void sub_140002FC0()
{
	char v1[24]; // [rsp+28h] [rbp-30h] BYREF
	char byte_1400804A8[30];

	v1[0] = 57;
	v1[1] = 23;
	v1[2] = 39;
	v1[3] = 28;
	v1[4] = 1;
	v1[5] = 6;
	v1[6] = 19;
	v1[7] = 17;
	v1[8] = 25;
	v1[9] = 54;
	v1[10] = 23;
	v1[11] = 6;
	v1[12] = 19;
	v1[13] = 17;
	v1[14] = 26;
	v1[15] = 34;
	v1[16] = 0;
	v1[17] = 29;
	v1[18] = 17;
	v1[19] = 23;
	v1[20] = 1;
	v1[21] = 1;
	v1[22] = 114;
	v1[23] = 114;
	xor_algorithm(v1, byte_1400804A8, 23);


}

void sub_140002EE8()
{
	char v1[32]; // [rsp+28h] [rbp-30h] BYREF
	char unk_1400804E8[30];
	v1[0] = 46;
	v1[1] = 13;
	v1[2] = 50;
	v1[3] = 17;
	v1[4] = 17;
	v1[5] = 21;
	v1[6] = 11;
	v1[7] = 14;
	v1[8] = 46;
	v1[9] = 12;
	v1[10] = 17;
	v1[11] = 29;
	v1[12] = 27;
	v1[13] = 13;
	v1[14] = 13;
	v1[15] = 60;
	v1[16] = 7;
	v1[17] = 46;
	v1[18] = 12;
	v1[19] = 17;
	v1[20] = 29;
	v1[21] = 27;
	v1[22] = 13;
	v1[23] = 13;
	v1[24] = 55;
	v1[25] = 26;
	v1[26] = 126;
	v1[27] = 126;
	xor_algorithm(v1, unk_1400804E8, 27);
	printf("%s\n", unk_1400804E8);
}

//

void xor_algorithm_6(char* a1, char* a2)
{

	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[13] ^ a1[v3];
		v3++;
	} while (a2[v3 - 1]);

}

//char sub_140003BD4()
//{
//	char v1[16]; // [rsp+28h] [rbp-20h] BYREF
//	char byte_140080510[20];
//	v1[0] = 50;
//	v1[1] = 31;
//	v1[2] = 44;
//	v1[3] = 13;
//	v1[4] = 4;
//	v1[5] = 13;
//	v1[6] = 28;
//	v1[7] = 13;
//	v1[8] = 46;
//	v1[9] = 1;
//	v1[10] = 4;
//	v1[11] = 13;
//	v1[12] = 104;
//	v1[13] = 104;
//	xor_algorithm_6(v1, byte_140080510);
//	printf("%s\n", byte_140080510);
//}

void sub_1400045C8(char* a1, char* a2)
{
	__int64 result; // rax
	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[11] ^ a1[v3];
		v3++;
	} while (a2[v3 - 1]);

}

void sub_140003C68()
{
	char v1[16]; // [rsp+28h] [rbp-20h] BYREF
	char unk_140080548[30];
	v1[0] = 52;
	v1[1] = 25;
	v1[2] = 60;
	v1[3] = 11;
	v1[4] = 15;
	v1[5] = 10;
	v1[6] = 40;
	v1[7] = 7;
	v1[8] = 2;
	v1[9] = 11;
	v1[10] = 110;
	v1[11] = 110;
	sub_1400045C8(v1, unk_140080548);
	printf("%s\n", unk_140080548);
}

void sub_140002078(char* a1, char* a2)
{
	__int64 result; // rax
	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[12] ^ a1[v3];
		v3++;
	} while (a2[v3 - 1]);

}

void sub_140003CF0()
{
	char v1[16]; // [rsp+28h] [rbp-20h] BYREF
	char unk_140080560[30];
	v1[0] = 51;
	v1[1] = 30;
	v1[2] = 62;
	v1[3] = 27;
	v1[4] = 0;
	v1[5] = 29;
	v1[6] = 12;
	v1[7] = 47;
	v1[8] = 0;
	v1[9] = 5;
	v1[10] = 12;
	v1[11] = 105;
	v1[12] = 105;
	sub_140002078(v1, unk_140080560);
	printf("%s\n", unk_140080560);
}
//





//void xor_algorithm_9(char* a1, char* a2)
//{
//	__int64 result; // rax
//	int v3; // [rsp+0h] [rbp-18h]
//
//	v3 = 0;
//	do
//	{
//		a2[v3] = a1[24] ^ a1[v3];
//		v3++;
//	}   while (a2[v3 - 1]);
//	
//}


//char sub_1400049C0()  // no work
//{
//	char v1[32]; // [rsp+28h] [rbp-30h] BYREF
//	char byte_1400805B0[100];
//	v1[0] = 45;
//	v1[1] = 14;
//	v1[2] = 47;
//	v1[3] = 24;
//	v1[4] = 27;
//	v1[5] = 24;
//	v1[6] = 15;
//	v1[7] = 24;
//	v1[8] = 19;
//	v1[9] = 30;
//	v1[10] = 24;
//	v1[11] = 45;
//	v1[12] = 15;
//	v1[13] = 20;
//	v1[14] = 16;
//	v1[15] = 28;
//	v1[16] = 15;
//	v1[17] = 4;
//	v1[18] = 41;
//	v1[19] = 18;
//	v1[20] = 22;
//	v1[21] = 24;
//	v1[22] = 19;
//	v1[23] = 125;
//	v1[24] = 125;
//	xor_algorithm_9(v1, byte_1400805B0);
//	printf("%s\n", byte_1400805B0);
//}




//char sub_140004A88()
//{
//	char v1[32]; // [rsp+28h] [rbp-30h] BYREF
//	char byte_1400805D0[60];
//	v1[0] = 42;
//	v1[1] = 12;
//	v1[2] = 20;
//	v1[3] = 59;
//	v1[4] = 23;
//	v1[5] = 22;
//	v1[6] = 14;
//	v1[7] = 29;
//	v1[8] = 10;
//	v1[9] = 12;
//	v1[10] = 43;
//	v1[11] = 17;
//	v1[12] = 28;
//	v1[13] = 44;
//	v1[14] = 23;
//	v1[15] = 45;
//	v1[16] = 22;
//	v1[17] = 17;
//	v1[18] = 27;
//	v1[19] = 23;
//	v1[20] = 28;
//	v1[21] = 29;
//	v1[22] = 43;
//	v1[23] = 12;
//	v1[24] = 10;
//	v1[25] = 17;
//	v1[26] = 22;
//	v1[27] = 31;
//	v1[28] = 120;
//	v1[29] = 120;
//	xor_algorithm(v1, byte_1400805D0, 29);
//	printf("%s\n", byte_1400805D0);
//}



void sub_1400055F4(char* a1, char* a2)
{
	__int64 result; // rax
	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[14] ^ a1[v3];
		v3++;
	} while (a2[v3 - 1]);

}

void sub_140004CE4()
{
	char v1[16]; // [rsp+28h] [rbp-20h] BYREF
	char unk_140080598[20];
	v1[0] = 49;
	v1[1] = 28;
	v1[2] = 36;
	v1[3] = 27;
	v1[4] = 14;
	v1[5] = 5;
	v1[6] = 59;
	v1[7] = 25;
	v1[8] = 4;
	v1[9] = 8;
	v1[10] = 14;
	v1[11] = 24;
	v1[12] = 24;
	v1[13] = 107;
	v1[14] = 107;
	sub_1400055F4(v1, unk_140080598);
	printf("%s\n", unk_140080598);
}
//
void sub_1400054E0(char* a1, char* a2)
{
	__int64 result; // rax
	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[19] ^ a1[v3];
		v3++;
	} while (a2[v3 - 1]);

}

void sub_140004C34()
{
	char v1[24]; // [rsp+28h] [rbp-30h] BYREF
	char unk_140080578[30];
	v1[0] = 44;
	v1[1] = 1;
	v1[2] = 34;
	v1[3] = 19;
	v1[4] = 4;
	v1[5] = 27;
	v1[6] = 31;
	v1[7] = 24;
	v1[8] = 23;
	v1[9] = 2;
	v1[10] = 19;
	v1[11] = 38;
	v1[12] = 4;
	v1[13] = 25;
	v1[14] = 21;
	v1[15] = 19;
	v1[16] = 5;
	v1[17] = 5;
	v1[18] = 118;
	v1[19] = 118;
	sub_1400054E0(v1, unk_140080578);
	printf("%s\n", unk_140080578);
}

//

//void sub_140003890(char* a1, char* a2)
//{
//	__int64 result; // rax
//	int v3; // [rsp+0h] [rbp-18h]
//
//	v3 = 0;
//	do
//	{
//		a2[v3] = a1[16] ^ a1[v3];
//		v3++;
//	}   while (a2[v3 - 1]);
//	
//}
//
//char sub_14000600C()
//{
//	char v1[24]; // [rsp+28h] [rbp-30h] BYREF
//	char byte_140080650[40];
//	v1[0] = 62;
//	v1[1] = 16;
//	v1[2] = 60;
//	v1[3] = 27;
//	v1[4] = 28;
//	v1[5] = 1;
//	v1[6] = 28;
//	v1[7] = 20;
//	v1[8] = 25;
//	v1[9] = 28;
//	v1[10] = 15;
//	v1[11] = 16;
//	v1[12] = 52;
//	v1[13] = 5;
//	v1[14] = 22;
//	v1[15] = 117;
//	v1[16] = 117;
//	sub_140003890(v1, byte_140080650);
//	printf("%s\n", byte_140080650);
//
//}


//


void sub_140006BB0(char* a1, char* a2)
{
	__int64 result; // rax
	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[17] ^ a1[v3];
		v3++;
	} while (a2[v3 - 1]);

}

void sub_1400060AC()
{
	char v1[24]; // [rsp+28h] [rbp-30h] BYREF
	char unk_140080668[50];
	v1[0] = 63;
	v1[1] = 17;
	v1[2] = 61;
	v1[3] = 26;
	v1[4] = 7;
	v1[5] = 17;
	v1[6] = 6;
	v1[7] = 0;
	v1[8] = 37;
	v1[9] = 1;
	v1[10] = 17;
	v1[11] = 1;
	v1[12] = 17;
	v1[13] = 53;
	v1[14] = 4;
	v1[15] = 23;
	v1[16] = 116;
	v1[17] = 116;
	sub_140006BB0(v1, unk_140080668);
	printf("%s\n", unk_140080668);
}
//
void sub_140007CB4(char* a1, char* a2)
{
	__int64 result; // rax
	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[18] ^ a1[v3];
		v3++;
	} while (a2[v3 - 1]);

}

void sub_140007174()
{
	char v1[24]; // [rsp+28h] [rbp-30h] BYREF
	char unk_140080710[30];
	v1[0] = 45;
	v1[1] = 0;
	v1[2] = 57;
	v1[3] = 24;
	v1[4] = 3;
	v1[5] = 30;
	v1[6] = 17;
	v1[7] = 14;
	v1[8] = 52;
	v1[9] = 31;
	v1[10] = 22;
	v1[11] = 25;
	v1[12] = 16;
	v1[13] = 18;
	v1[14] = 60;
	v1[15] = 18;
	v1[16] = 14;
	v1[17] = 119;
	v1[18] = 119;
	sub_140007CB4(v1, unk_140080710);
	printf("%s\n", unk_140080710);
}



void sub_140003890(char* a1, char* a2)
{
	__int64 result; // rax
	int v3; // [rsp+0h] [rbp-18h]

	v3 = 0;
	do
	{
		a2[v3] = a1[16] ^ a1[v3];
		v3++;
	} while (a2[v3 - 1]);

}

void sub_140002E48()
{
	char v1[24]; // [rsp+28h] [rbp-30h] BYREF
	char unk_140080490[40];
	v1[0] = 37;
	v1[1] = 6;
	v1[2] = 50;
	v1[3] = 16;
	v1[4] = 1;
	v1[5] = 37;
	v1[6] = 7;
	v1[7] = 26;
	v1[8] = 22;
	v1[9] = 16;
	v1[10] = 6;
	v1[11] = 6;
	v1[12] = 37;
	v1[13] = 16;
	v1[14] = 23;
	v1[15] = 117;
	v1[16] = 117;
	sub_140003890(v1, unk_140080490);
	printf("%s\n", unk_140080490);
}

void sub_140003184()
{
	char v1[24]; // [rsp+28h] [rbp-30h] BYREF
	char byte_1400804C8[30];
	v1[0] = 59;
	v1[1] = 21;
	v1[2] = 35;
	v1[3] = 4;
	v1[4] = 17;
	v1[5] = 19;
	v1[6] = 27;
	v1[7] = 49;
	v1[8] = 4;
	v1[9] = 4;
	v1[10] = 17;
	v1[11] = 19;
	v1[12] = 24;
	v1[13] = 32;
	v1[14] = 2;
	v1[15] = 31;
	v1[16] = 19;
	v1[17] = 21;
	v1[18] = 3;
	v1[19] = 3;
	v1[20] = 112;
	v1[21] = 112;
	xor_algorithm(v1, byte_1400804C8, 21);
	printf("%s\n", byte_1400804C8);
}

void sub_140003BD4()
{
	char v1[16]; // [rsp+28h] [rbp-20h] BYREF
	char byte_140080510[30];
	v1[0] = 50;
	v1[1] = 31;
	v1[2] = 44;
	v1[3] = 13;
	v1[4] = 4;
	v1[5] = 13;
	v1[6] = 28;
	v1[7] = 13;
	v1[8] = 46;
	v1[9] = 1;
	v1[10] = 4;
	v1[11] = 13;
	v1[12] = 104;
	v1[13] = 104;
	xor_algorithm(v1, byte_140080510, 13);
	printf("%s\n", byte_140080510);
}

void sub_1400049C0()
{
	char v1[32]; // [rsp+28h] [rbp-30h] BYREF
	char byte_1400805B0[40];
	v1[0] = 45;
	v1[1] = 14;
	v1[2] = 47;
	v1[3] = 24;
	v1[4] = 27;
	v1[5] = 24;
	v1[6] = 15;
	v1[7] = 24;
	v1[8] = 19;
	v1[9] = 30;
	v1[10] = 24;
	v1[11] = 45;
	v1[12] = 15;
	v1[13] = 20;
	v1[14] = 16;
	v1[15] = 28;
	v1[16] = 15;
	v1[17] = 4;
	v1[18] = 41;
	v1[19] = 18;
	v1[20] = 22;
	v1[21] = 24;
	v1[22] = 19;
	v1[23] = 125;
	v1[24] = 125;
	xor_algorithm(v1, byte_1400805B0, 24);
	printf("%s\n", byte_1400805B0);
}


void sub_140004A88()
{
	char v1[32]; // [rsp+28h] [rbp-30h] BYREF
	char byte_1400805D0[40];
	v1[0] = 42;
	v1[1] = 12;
	v1[2] = 20;
	v1[3] = 59;
	v1[4] = 23;
	v1[5] = 22;
	v1[6] = 14;
	v1[7] = 29;
	v1[8] = 10;
	v1[9] = 12;
	v1[10] = 43;
	v1[11] = 17;
	v1[12] = 28;
	v1[13] = 44;
	v1[14] = 23;
	v1[15] = 45;
	v1[16] = 22;
	v1[17] = 17;
	v1[18] = 27;
	v1[19] = 23;
	v1[20] = 28;
	v1[21] = 29;
	v1[22] = 43;
	v1[23] = 12;
	v1[24] = 10;
	v1[25] = 17;
	v1[26] = 22;
	v1[27] = 31;
	v1[28] = 120;
	v1[29] = 120;
	xor_algorithm(v1, byte_1400805D0, 29);
	printf("%s\n", byte_1400805D0);
}
void kernelCode() {
//
	KAPC_STATE state;
	KeStackAttachProcess(proc, &state);

	PPEB pPeb = (PPEB)PsGetProcessPeb(proc);
	if (!pPeb)
	{
		return 0;
	}
	PPEB_LDR_DATA pLdr = (PPEB_LDR_DATA)pPeb->Ldr;

	if (!pLdr)
	{
		KeUnstackDetachProcess(&state);
		return 1;
	}

	UNICODE_STRING name;

	for (PLIST_ENTRY list = (PLIST_ENTRY)pLdr->ModuleListLoadOrder.Flink;
		list != &pLdr->ModuleListLoadOrder; list = (PLIST_ENTRY)list->Flink)
	{
		PLDR_DATA_TABLE_ENTRY pEntry =
			CONTAINING_RECORD(list, LDR_DATA_TABLE_ENTRY, InLoadOrderModuleList);
		if (RtlCompareUnicodeString(&pEntry->BaseDllName, &module_name, TRUE) ==
			0) {
			ULONG64 baseAddr = (ULONG64)pEntry->DllBase;
		KeUnstackDetachProcess(&state);
		return baseAddr;
		}
	}
	KeUnstackDetachProcess(&state);
}




void sub_140005EE0()
{
	char v1[16]; // [rsp+28h] [rbp-20h] BYREF
	char unk_1400806B8[30];
	memcpy(v1, "!;+##A+##oo", 11);
	xor_algorithm(v1, unk_1400806B8, 10);
	printf("%s\n", unk_1400806B8);
}
void sub_14000600C()
{
	char v1[24]; // [rsp+28h] [rbp-30h] BYREF
	char byte_140080650[40];
	v1[0] = 62;
	v1[1] = 16;
	v1[2] = 60;
	v1[3] = 27;
	v1[4] = 28;
	v1[5] = 1;
	v1[6] = 28;
	v1[7] = 20;
	v1[8] = 25;
	v1[9] = 28;
	v1[10] = 15;
	v1[11] = 16;
	v1[12] = 52;
	v1[13] = 5;
	v1[14] = 22;
	v1[15] = 117;
	v1[16] = 117;
	xor_algorithm(v1, byte_140080650, 16);
	printf("%s\n", byte_140080650);
}

void sub_140006CA0()
{
	char v1[32]; // [rsp+28h] [rbp-30h] BYREF
	char byte_1400806F0[40];
	v1[0] = 51;
	v1[1] = 9;
	v1[2] = 60;
	v1[3] = 17;
	v1[4] = 17;
	v1[5] = 18;
	v1[6] = 30;
	v1[7] = 28;
	v1[8] = 9;
	v1[9] = 24;
	v1[10] = 43;
	v1[11] = 20;
	v1[12] = 15;
	v1[13] = 9;
	v1[14] = 8;
	v1[15] = 28;
	v1[16] = 17;
	v1[17] = 48;
	v1[18] = 24;
	v1[19] = 16;
	v1[20] = 18;
	v1[21] = 15;
	v1[22] = 4;
	v1[23] = 125;
	v1[24] = 125;
	xor_algorithm(v1, byte_1400806F0, 24);
	printf("%s\n", byte_1400806F0);
}

void sub_140006D68()
{
	char v1[24]; // [rsp+28h] [rbp-30h] BYREF
	char byte_1400806D0[40];
	v1[0] = 62;
	v1[1] = 4;
	v1[2] = 39;
	v1[3] = 2;
	v1[4] = 25;
	v1[5] = 4;
	v1[6] = 21;
	v1[7] = 38;
	v1[8] = 25;
	v1[9] = 2;
	v1[10] = 4;
	v1[11] = 5;
	v1[12] = 17;
	v1[13] = 28;
	v1[14] = 61;
	v1[15] = 21;
	v1[16] = 29;
	v1[17] = 31;
	v1[18] = 2;
	v1[19] = 9;
	v1[20] = 112;
	v1[21] = 112;
	xor_algorithm(v1, byte_1400806D0, 21);
	printf("%s\n", byte_1400806D0);
}


void sub_140005E44()
{
	char v1[16]; // [rsp+28h] [rbp-20h] BYREF
	char unk_1400806A8[40];
	v1[0] = 36;
	v1[1] = 30;
	v1[2] = 56;
	v1[3] = 15;
	v1[4] = 25;
	v1[5] = 31;
	v1[6] = 7;
	v1[7] = 15;
	v1[8] = 62;
	v1[9] = 2;
	v1[10] = 24;
	v1[11] = 15;
	v1[12] = 11;
	v1[13] = 14;
	v1[14] = 106;
	v1[15] = 106;
	xor_algorithm(v1, unk_1400806A8, 15);
	printf("%s\n", unk_1400806A8);
}



void sub_140005F64()
{
	char v1[24]; // [rsp+28h] [rbp-30h] BYREF
	char byte_140080688[50];

	v1[0] = 58;
	v1[1] = 0;
	v1[2] = 55;
	v1[3] = 6;
	v1[4] = 17;
	v1[5] = 21;
	v1[6] = 0;
	v1[7] = 17;
	v1[8] = 32;
	v1[9] = 28;
	v1[10] = 6;
	v1[11] = 17;
	v1[12] = 21;
	v1[13] = 16;
	v1[14] = 49;
	v1[15] = 12;
	v1[16] = 116;
	v1[17] = 116;

	xor_algorithm(v1, byte_140080688, 17);
	printf("%s\n", byte_140080688);
}

int main() {

	dotSysStr();
	sub_140008310();//zsrvnet2
	sub_140007F8C(); //\systemroot\system32\drivers
	sub_140007EA8();
	sub_1400023F4();
	sub_140003B10();
	sub_1400012D0();
	sub_140001000();//PsTerminateSystemThread
	sub_1400010C8();//ZwClose
	sub_140002FC0();
	sub_140002EE8();
	sub_140003BD4();
	sub_140003C68();
	sub_140003CF0();
	sub_1400049C0(); 
	sub_140004A88(); 
	sub_140004CE4();
	sub_140004C34();
	sub_14000600C();
	sub_1400060AC();
	sub_140007174();
	sub_140002E48();
	sub_140003184();
	sub_140003BD4();
	sub_1400049C0();
	sub_140004A88();
	sub_14000600C();
	sub_140005EE0();
	sub_140006CA0();
	sub_140006D68();

	sub_140005E44();
	sub_140005F64();

	getchar();
	return 0;
}









