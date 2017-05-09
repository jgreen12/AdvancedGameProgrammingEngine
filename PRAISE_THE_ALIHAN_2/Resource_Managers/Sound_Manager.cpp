//From Matt Hopson's SFML Game Engine Tutorial well based because he said Music is done differently.
//https://www.youtube.com/watch?v=hZ9iviK6v-I&list=PLMZ_9w2XRxiaz3_mrIviTEg4-BcFFjFDS

#include "Sound_Manager.h"

Sound_Manager::Sound_Manager() //This is where you add new audio files. Easier if all placed in Res folder / Sounds folder
{								//Don't forget to head to the header file too.
	//example of new audio file
	//addResource(Sound_Name::audioExample, "Res/Sounds/Example.ogg");

	//Background Music
    addResource(Sound_Name::Aries, "Res/Music/AerisPianoByTannerHelland.ogg");

	//Music
	addResource(Sound_Name::StageClear, "Res/Music/smb_stage_clear.wav");

	//Sound Effects
	addResource(Sound_Name::MarioSmallJump, "Res/Sounds/smb_jump-small.wav");
	addResource(Sound_Name::MarioSuperJump, "Res/Sounds/smb_jump-super.wav");
	
}

//This is how you set up the buffer
//
// sound.setBuffer(Resource_Holder::get().getSoundBuff(Sound_Name::Example)); //*warning* bit loud
//
//And this will start playing the the soundbuffer
//
// sound.play();
//
//
//
//
//
//For Music use these lines of code
//
//sf::Music music;			//initializes music
//
//if (!music.openFromFile("Res/Music/AerisPianoByTannerHelland.ogg"))		//This loads the song while also checking if it exists
//{
//	std::cout << "Error" << std::endl;
//}
//
//music.play();				//plays the music
//
//(bunch of code)			//your random code stuff
//
//music.stop();				//place this at the end in order to clear the music data
//return 0;					//example of where the end is