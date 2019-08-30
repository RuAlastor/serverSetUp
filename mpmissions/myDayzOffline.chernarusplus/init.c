//#include "$CurrentDir:..."


#include "$CurrentDir:mpmissions\\myDayzOffline.chernarusplus\\scripts\\defaultSetup.c"

void main()
{
	Weather o_weather 	= setupWeather();
	Hive	o_hive 		= setupEconomy();
	
	setupDate();
}