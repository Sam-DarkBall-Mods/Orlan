private _positionATL = getPosATLVisual cameraOn;

// CURSOR ANGLE VERTICAL MOVEMENT
private _cursorPicture = uiNameSpace getVariable ["DB_orlanHUD_angle_cursorPicture", controlNull];
private _cursorMaxH = (ctrlPosition (ctrlParentControlsGroup _cursorPicture)) # 3;
private _turretY = ([cameraOn, [0], true] call CBA_fnc_turretDir) # 1;

_cursorPicture ctrlSetPositionY (linearConversion [10, -80, _turretY, 0, _cursorMaxH - ((ctrlPosition _cursorPicture) # 3), true]);
_cursorPicture ctrlCommit 0.0;

// CURSOR ANGLE TEXT
private _cursorMainText = uiNameSpace getVariable ["DB_orlanHUD_angle_mainText", controlNull];
_cursorMainText ctrlSetText (str(round _turretY));

// ALT
private _altMainText = uiNameSpace getVariable ["DB_orlanHUD_alt_mainText", controlNull];
_altMainText ctrlSetText format ["ВЫС: %1", floor(cameraOn call CBA_fnc_realHeight)];

// COORDINATES
private _coordMainText = uiNameSpace getVariable ["DB_orlanHUD_coord_mainText", controlNull];
_coordMainText ctrlSetText format ["СЕТКА: %1 %2", floor((_positionATL # 0) / 100), floor((_positionATL # 1) / 100)];

// FUEL
private _fuelMainText = uiNameSpace getVariable ["DB_orlanHUD_fuel_mainText", controlNull];
_fuelMainText ctrlSetText format ["ТОПЛИВО: %1", floor (fuel cameraOn * 100)];

// LASER
private _laserMainText = uiNameSpace getVariable ["DB_orlanHUD_laser_mainText", controlNull];
_laserMainText ctrlSetText format ["ЛАЗЕР: %1", ["ВЫКЛ", "ВКЛ"] select (isLaserOn cameraOn)];

// STATUS
private _statusMainText = uiNameSpace getVariable ["DB_orlanHUD_status_mainText", controlNull];
_statusMainText ctrlSetText format ["СОСТОЯНИЕ: %1", ["УПРАВЛЯЕМЫЙ", "ПОВРЕЖДЕН"] select (damage cameraOn >= 0.33)];

// DIRECTION
private _directionPicture = uiNameSpace getVariable ["DB_orlanHUD_direction_picture", controlNull];
private _directionMainText = uiNameSpace getVariable ["DB_orlanHUD_direction_mainText", controlNull];
private _picture = "";
private _direction = getDirVisual cameraOn;
private _laserTarget = laserTarget cameraOn;

switch (true) do {
	case ((_direction >= 0) and (_direction < 30)):    { _picture = "\orlan\pictures\12.paa" };
	case ((_direction >= 30) and (_direction < 60)):   { _picture = "\orlan\pictures\12.paa" };
	case ((_direction >= 60) and (_direction < 90)):   { _picture = "\orlan\pictures\12.paa" };
	case ((_direction >= 90) and (_direction < 120)):  { _picture = "\orlan\pictures\12.paa" };
	case ((_direction >= 120) and (_direction < 150)): { _picture = "\orlan\pictures\12.paa" };
	case ((_direction >= 150) and (_direction < 180)): { _picture = "\orlan\pictures\12.paa" };
	case ((_direction >= 180) and (_direction < 210)): { _picture = "\orlan\pictures\12.paa"  };
	case ((_direction >= 210) and (_direction < 240)): { _picture = "\orlan\pictures\12.paa" };
	case ((_direction >= 240) and (_direction < 270)): { _picture = "\orlan\pictures\12.paa" };
	case ((_direction >= 270) and (_direction < 300)): { _picture = "\orlan\pictures\12.paa" };
	case ((_direction >= 300) and (_direction < 330)): { _picture = "\orlan\pictures\12.paa" };
	case ((_direction >= 330) and (_direction < 359)): { _picture = "\orlan\pictures\12.paa" };
	default { };
};

_directionPicture ctrlSetText _picture;
_directionMainText ctrlSetText str(floor _direction);

// LASER DISTANCE
private _laserDistanceMainText = uiNameSpace getVariable ["DB_orlanHUD_laserDistance_mainText", controlNull];
_laserDistanceMainText ctrlSetText format ["%1", ["ВЫКЛ", format["%1 м.", floor(cameraOn distance _laserTarget)]] select !(isNull _laserTarget)];

// FOV
private _uavFOV = getObjectFOV cameraOn;

"DynamicBlur" ppEffectEnable false;
"filmGrain" ppEffectEnable false;

switch true do {

    case (_uavFOV >= 0.0124 && _uavFOV <= 0.0126): {
        "DynamicBlur" ppEffectEnable true;
        "filmGrain" ppEffectEnable true;
        "filmGrain" ppEffectAdjust [0.3,1,1,0.5,0.5,true];
        "filmGrain" ppEffectCommit 0; 
        "DynamicBlur" ppEffectAdjust [0.4]; 
        "DynamicBlur" ppEffectCommit 0;
    };

    case (_uavFOV >= 0.02 && _uavFOV <= 0.026): {
        "DynamicBlur" ppEffectEnable true;
        "filmGrain" ppEffectEnable true;
        "filmGrain" ppEffectAdjust [0.1,1,1,0.5,0.5,true];  
        "filmGrain" ppEffectCommit 0; 
        "DynamicBlur" ppEffectAdjust [0.3]; 
        "DynamicBlur" ppEffectCommit 0;
    };
    
    case (_uavFOV >= 0.04 && _uavFOV <= 0.03): {
        "DynamicBlur" ppEffectEnable true;
        "filmGrain" ppEffectEnable true;
        "filmGrain" ppEffectAdjust [0.2,1,1,0.5,0.5,true];
        "filmGrain" ppEffectCommit 0; 
        "DynamicBlur" ppEffectAdjust [0.35]; 
        "DynamicBlur" ppEffectCommit 0;
    };
};

// OTHER
call orlan_fnc_drawCompass;