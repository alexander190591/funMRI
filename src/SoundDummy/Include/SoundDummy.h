#include "ISoundModule.h"
#include <stdint.h>

class SoundDummy : public ISoundModule
{
public:
    SoundDummy(uint8_t ledPin);
    void playSound() override;
	void stopSound() override;
protected:
	void init() override;

private:
    uint8_t _ledPin = 0;
};