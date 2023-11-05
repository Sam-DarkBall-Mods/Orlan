//if(!(alive player)) exitWith {};

params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile"];

_UAV = _unit getvariable ['proxy',objnull];

if (!(isnull _UAV) && (_UAV in (attachedobjects _unit))) then
{

_UAV engineON true;sleep 0.1;_UAV setAirplaneThrottle 1;
waituntil {sleep 1;(airplaneThrottle _UAV == 1) || !(alive _UAV)};
(gunner _unit) remoteControl (driver _UAV);
playSound3D ['\orlan\tripod\zapusk.ogg', _unit, false, getPosASL _unit, 5];
_unit animatesource ['luch_anim',1,4.8];
_unit animatesource ['reload_uav',1,true];

waituntil {sleep 0.01;(_unit animationsourcephase 'luch_anim' > 0.95) || !(alive _unit) || !(alive _UAV)};

detach _UAV;//_UAV setVehicleLock "LOCKED";
//_UAV setpos [(getpos _UAV)#0,(getpos _UAV)#1,100];
_UAV setVelocityModelSpace [0,30,0];
_UAV setAirplaneThrottle 1;
waituntil {sleep 1;(airplaneThrottle _UAV == 1) || !(alive _UAV)};
(gunner _unit) remoteControl objnull;

_unit setvariable ['proxy',objnull,true];
};
