/*modded class MissionMainMenu extends MissionBase
{
	override void PlayMusic()
	{
		int rnd_interval = Math.RandomInt(0,37)
		string soundsetstring = "Music_Menu_SoundSet" + rnd_interval;
		
		if ( !m_MenuMusic )
		{
			ref SoundParams soundParams			= new SoundParams( "Music_Menu_SoundSet" );
			ref SoundObjectBuilder soundBuilder	= new SoundObjectBuilder( soundParams );
			ref SoundObject soundObject			= soundBuilder.BuildSoundObject();
			soundObject.SetKind( WaveKind.WAVEMUSIC );
			m_MenuMusic = GetGame().GetSoundScene().Play2D(soundObject, soundBuilder);
			m_MenuMusic.Loop( false );
			
			m_MenuMusic.Play();
		}
	}
};
