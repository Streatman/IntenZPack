class CfgPatches
{
	class IntenZ_MuchStuff
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"MSP_Storage_crates",
			"MSP_Scripts"
		};
	};
};

class CfgMods
{
	class IntenZ_MuchStuff
	{
		type = "mod";
		dependencies[] = {"World"};
		
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"IntenZ\MuchStuff\Scripts\4_World"};
			};
		};
	};
};

class CfgVehicles
{
	class Container_Base;
	class Msp_Kit: Container_Base
	{
		itemSize[] = {10,7};
		weight = 15000;
	};
};
