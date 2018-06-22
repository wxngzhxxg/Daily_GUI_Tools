#include "trainerbase.h"

/*
本文件函数用于循环读取内存以更新显示值
*/

// address table. might not be universal.
// will test after all wrapedup.


// 0. the followings are for all courts. 
DWORD exe_base_addr				= 0x00400000;	// nba2k11.exe基址，不知道会不会变化。后面的地址都是基址+偏移量后的地址。
// e.g. single practice, blacktop street, shooting practice, etc. 
DWORD score_type_addr			= 0x05D5FA70;	// 球与篮筐关系，0三不沾1砸框2空刷3打板 5大号空刷/偏出？ 7大号砸框进/砸板上沿8弹框而出，经过圆柱体
DWORD score_judge_addr			= 0x05D5FA78;	// 进球判断
DWORD coordinate_x_100_addr		= 0x05d5f720;	// 百倍横坐标
DWORD coordinate_y_100_addr		= 0x05d5f728;	// 百倍纵坐标
DWORD absolute_dist_rim_addr	= 0x05d5f730;	// 距离篮筐绝对距离
DWORD projected_percent_addr	= 0x05d5f738;	// 预计投篮命中率，可参考以提升投篮选择
DWORD shot_triggered_time_addr	= 0x05db028c;	// 投篮释放时间，即按下z投篮键后键抬起的时间，可用于判断是否扣篮，秒数
DWORD total_time_elapsed_addr	= 0x05439C1C;	// 总流逝时间，包括暂停表演等，不包括esc游戏暂停

// 1. the followings are for quartered games, e.g.
// dynasty, quick game, mplayer, jordan, etc.
DWORD game_time_elapsed_addr	= 0x05544DF4;	// 比赛流逝时间，仅适用于分节比赛的模式，秒数





void update_score_type(HANDLE pHandle) {
	ReadProcessMemory(pHandle, (LPVOID)score_type_addr, &score_type, sizeof(score_type), 0);
	ReadProcessMemory(pHandle, (LPVOID)score_judge_addr, &score_judge, sizeof(score_judge), 0);
}


// only read from global flags and the handle for address
void UpdateDMAs(HANDLE pHandle) {
	// aka direct memory access. manipulate the memory region.
	update_score_type(pHandle);
}