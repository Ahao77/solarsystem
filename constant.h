/**
*公司：杭州图华科技有限公司
*版权信息：图华所有
*任务：太阳系模拟构建实习作业
*描述：常量规定的头文件
*
*版本：1.1
*作者：叶广平
*日期：2019/4/25
**/
#pragma once

const float planetSizeScale = 0.000025f;//星球半径的比例尺

const float distanceScale = 0.00000001f;//星球离太阳距离的比例尺

const float PI = 3.14159265f;

const float rate = 0.01f;//鼠标移动灵敏度

enum currentplanet//当前观察的星球标志
{
	Sun,Mercury,Venus,Earth,Mars,
	Jupiter,Saturn,Uranus,Neptune,Pluto
};

enum star_mode//背景星星的模式标志
{
	SMALL_STAR,BIG_STAR
};