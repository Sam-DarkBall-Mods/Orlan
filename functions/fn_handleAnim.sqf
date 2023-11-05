params ["_unit"];

_reloadtime = 55;

_drone_type = "orlan_F";//"O_T_UAV_04_CAS_F";

while {alive _unit} do
{
	waituntil {sleep 1;(someammo _unit) || !(alive _unit)};

	if ((_unit animationsourcephase 'luch_anim' > 0) || (_unit animationsourcephase 'reload_uav' > 0))	then {_unit animatesource ['luch_anim',0,(1/_reloadtime)];_unit animatesource ['reload_uav',0,(1/_reloadtime)]};

	waituntil {sleep 1;((_unit animationsourcephase 'reload_uav' == 0) && (_unit animationsourcephase 'luch_anim' == 0)) || !(alive _unit)};

	if ((isnull (_unit getvariable ['proxy',objnull])) && (someammo _unit) && (_unit animationsourcephase 'luch_anim' == 0) && (_unit animationsourcephase 'reload_uav' == 0) && (alive _unit)) then
	{
		_UAV =  _drone_type createVehicle (_unit modeltoworld (_unit selectionposition "pos_luncher"));
		createVehicleCrew _uav;
		_UAV attachto [_unit,[0,0,0],"pos_luncher",true];
		_UAV setVectorDirAndUp [[0,0.8,0.2],[0,0,1]];
		_unit setvariable ['proxy',_UAV,true];UAV = _UAV;
	};
	//systemchat "reloaded";
	waituntil {sleep 1;(!(someammo _unit) && (_unit animationsourcephase 'luch_anim' == 1) && (_unit animationsourcephase 'reload_uav' == 1)) || !(alive _unit)};
};
