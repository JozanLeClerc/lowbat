#include <jo_lowbat.hpp>
#include <iostream>
#include <cstring>
#include <cstdint>
#include <thread>
#include <chrono>

using namespace this_thread;
using namespace chrono;

int main(int argc, const char *argv[]) {
	Lowbat	lowbat;
	uint8_t	speaks;

	speaks = 0;
	if (lowbat.jo_testNotifySend()) {
		return (JO_RET_MISS_DEP);
	}
	if (argc > 2 && !strcmp(argv[1], "--say")) {
		if (!lowbat.jo_testEspeak()) {
			speaks = 1;
		}
	}
	while (true) {
		while (lowbat.jo_fetchBatlvl() < 15 && !lowbat.jo_fetchAcstat()) {
			if (lowbat.jo_notify()) {
				cerr << "Error: could not use notify-send" << endl;
				return (JO_RET_NOTIFY_FAILED);
			}
			if (speaks) {
				lowbat.jo_setMsg(argv[2]);
				lowbat.jo_speak();
				lowbat.jo_delMsg();
				cerr << "Error: could not use espeak" << endl;
			}
			cout << "Sleep for 20s" << endl;
			sleep_for(seconds(20));
		}
		cout << "Sleep for 4m" << endl;
		sleep_for(seconds(240));
	}
	return (JO_RET_FINE);
}
