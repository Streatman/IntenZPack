modded class TLRLight extends Switchable_Base
{
	PistollightLight 	m_Light;
	
	static int		REFLECTOR_ID = 1;
	static int		GLASS_ID = 0;

	static string 	LIGHT_ON_GLASS 		= "dz\\gear\\tools\\data\\flashlight_glass_on.rvmat";	
	static string 	LIGHT_OFF_GLASS 	= "dz\\gear\\tools\\data\\flashlight_glass.rvmat";
	static string 	LIGHT_ON_REFLECTOR 	= "dz\\weapons\\attachments\\data\\TLS3_on.rvmat";
	static string 	LIGHT_OFF_REFLECTOR = "dz\\weapons\\attachments\\data\\TLS3.rvmat";
	
	static string 	LIGHT_ON_GLASS_RED		= "dz\\characters\\headgear\\data\\HeadTorchGlass_on_red.rvmat";
	static string 	LIGHT_ON_REFLECTOR_RED	= "dz\\characters\\headgear\\data\\HeadTorch_ON_red.rvmat";

	override void OnWorkStart()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() ) // Client side
		{
			CreatePistollightLight();
			m_Light.AttachOnMemoryPoint(this, "beamStart", "beamEnd");
		}
		
		if ( IsInherited( TLRLight_Red ) )
		{
			SetObjectMaterial(GLASS_ID, LIGHT_ON_GLASS_RED);
			SetObjectMaterial(REFLECTOR_ID, LIGHT_ON_REFLECTOR_RED);
		}
		else
		{
			SetObjectMaterial(GLASS_ID, LIGHT_ON_GLASS);
			SetObjectMaterial(REFLECTOR_ID, LIGHT_ON_REFLECTOR);
		}
	}

	void OnLightCreated()
	{
		m_Light.SetColorToWhite();
	}
	
	void CreatePistollightLight()
	{
		if (!m_Light)
			m_Light = PistollightLight.Cast(  ScriptedLightBase.CreateLight( PistollightLight, "0 0 0", 0.08)  );
		
		OnLightCreated();
	}
}

class TLRLight_Red: TLRLight
{
	override void OnLightCreated()
	{
		m_Light.SetColorToRed();
	}
}
