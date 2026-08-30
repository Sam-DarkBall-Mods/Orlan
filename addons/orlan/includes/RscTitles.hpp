#include "uiDefines.hpp"

#define UI_EXPR_INNER(value) #value
#define UI_EXPR(value) UI_EXPR_INNER(value)

class InfoBox_Base : ctrlControlsGroupNoScrollBars
{
    idc = -1;

    x = 0;
    y = 0;
    w = UI_EXPR(INFOBOX_W);
    h = UI_EXPR(INFOBOX_H);

    class controls
    {
        class WhiteBackGround : ctrlStaticBackGround
        {
            idc = -1;

            colorBackGround[] = {1, 1, 1, 1};

            x = 0;
            y = 0;
            w = UI_EXPR(INFOBOX_W);
            h = UI_EXPR(INFOBOX_H);
        };

        class TopBackGround : ctrlStaticBackGround
        {
            idc = -1;

            colorBackGround[] = {0, 0, 0, 1};

            x = UI_EXPR(INFOBOX_PADDING_W);
            y = UI_EXPR(INFOBOX_PADDING_H);
            w = UI_EXPR(INFOBOX_W - 2*INFOBOX_PADDING_W);
            h = UI_EXPR(INFOBOX_H - 2*INFOBOX_PADDING_H);
        };
        
        class MainText : ctrlStructuredText
        {
            idc = -1;

            class Attributes
            {
                font = "PuristaLight";
                align = "center";
                valign = "middle";
            };

            size = UI_EXPR(INFOBOX_TEXT_SIZE);

            x = 0;
            y = UI_EXPR(INFOBOX_H / 2 - INFOBOX_TEXT_SIZE / 2);
            w = UI_EXPR(INFOBOX_W);
            h = UI_EXPR(INFOBOX_TEXT_SIZE);
        };
    };
};

class RscTitles
{
    class Orlan_HUD
    {
        duration = 1e10;
		movingEnable = 0;
		enableSimulation = 1;
		idd = -1;

        onLoad = "uiNamespace setVariable ['DB_orlanHUD_display', _this # 0]";

        class controls
        {
            
            class AngleBox : InfoBox_Base
            {
                x = UI_EXPR(ANGLE_GROUP_X);
                y = UI_EXPR(ANGLE_GROUP_Y);

                class controls : controls
                {
                    class WhiteBackGround : WhiteBackGround {};
                    class TopBackGround : TopBackGround {};
                    class MainText : MainText
                    {
                        onLoad = "uiNamespace setVariable ['DB_orlanHUD_angle_mainText', _this # 0]";
                        text = "19";
                    };
                };
            };

            class AngleScale_Group : ctrlControlsGroupNoScrollBars
            {
                idc = -1;

                x = UI_EXPR(ANGLE_GROUP_X + INFOBOX_W / 2 - ANGLE_SCALE_W / 2);
                y = UI_EXPR(ANGLE_GROUP_Y + INFOBOX_H);
                w = UI_EXPR(3*ANGLE_SCALE_W);
                h = UI_EXPR(ANGLE_SCALE_H);

                class controls
                {
                    class LinePicture : ctrlStaticPicture
                    {
                        idc = -1;

                        text = "\orlan\pictures\line.paa";

                        x = 0;
                        y = 0;
                        w = UI_EXPR(ANGLE_SCALE_W);
                        h = UI_EXPR(ANGLE_SCALE_H);
                    };

                    class CursorPicture : ctrlStaticPicture
                    {
                        idc = -1;

                        onLoad = "uiNamespace setVariable ['DB_orlanHUD_angle_cursorPicture', _this # 0]";

                        text = "\orlan\pictures\triangle.paa";

                        x = UI_EXPR(ANGLE_SCALE_W - GRID_W(1));
                        y = 0;
                        w = UI_EXPR(GRID_W(3));
                        h = UI_EXPR(GRID_H(3));
                    };
                };
            };

            class LaserBox : InfoBox_Base
            {
                x = UI_EXPR(ANGLE_GROUP_X + INFOBOX_W + GRID_W(1));
                y = UI_EXPR(ANGLE_GROUP_Y - INFOBOX_H);
                w = UI_EXPR(GRID_W(8));

                class controls : controls
                {
                    class WhiteBackGround : WhiteBackGround {
                        w = UI_EXPR(GRID_W(8));
                    };
                    class TopBackGround : TopBackGround {
                        w = UI_EXPR(GRID_W(8) - 2*INFOBOX_PADDING_W);
                    };
                    class MainText : MainText
                    {
                        text = "LASER: ON";
                        onLoad = "uiNamespace setVariable ['DB_orlanHUD_laser_mainText', _this # 0]";
                        w = UI_EXPR(GRID_W(8));
                    };
                };
            };

            class CoordinateBox : InfoBox_Base
            {
                x = UI_EXPR(ANGLE_GROUP_X + INFOBOX_W + GRID_W(8) + GRID_W(1) + GRID_W(0.5));
                y = UI_EXPR(ANGLE_GROUP_Y - INFOBOX_H);
                w = UI_EXPR(GRID_W(12));

                class controls : controls
                {
                    class WhiteBackGround : WhiteBackGround {
                        w = UI_EXPR(GRID_W(12));
                    };
                    class TopBackGround : TopBackGround {
                        w = UI_EXPR(GRID_W(12) - 2*INFOBOX_PADDING_W);
                    };
                    class MainText : MainText
                    {
                        onLoad = "uiNamespace setVariable ['DB_orlanHUD_coord_mainText', _this # 0]";
                        text = "3535.85, 4887.42, 500";
                        w = UI_EXPR(GRID_W(12));
                    };
                };
            };

            class BatteryBox : InfoBox_Base
            {
                x = UI_EXPR(ANGLE_GROUP_X + INFOBOX_W + GRID_W(8) + GRID_W(12) + GRID_W(1) + 2*GRID_W(0.5));
                y = UI_EXPR(ANGLE_GROUP_Y - INFOBOX_H);
                w = UI_EXPR(GRID_W(8));

                class controls : controls
                {
                    class WhiteBackGround : WhiteBackGround {
                        w = UI_EXPR(GRID_W(8));
                    };
                    class TopBackGround : TopBackGround {
                        w = UI_EXPR(GRID_W(8) - 2*INFOBOX_PADDING_W);
                    };
                    class MainText : MainText
                    {
                        text = "BATTERY: 100";
                        onLoad = "uiNamespace setVariable ['DB_orlanHUD_fuel_mainText', _this # 0]";
                        w = UI_EXPR(GRID_W(8));
                    };
                };
            };

            class AltitudeBox : InfoBox_Base
            {
                x = UI_EXPR(ANGLE_GROUP_X + INFOBOX_W + 2*GRID_W(8) + GRID_W(12) + GRID_W(1) + 3*GRID_W(0.5));
                y = UI_EXPR(ANGLE_GROUP_Y - INFOBOX_H);
                w = UI_EXPR(GRID_W(8));

                class controls : controls
                {
                    class WhiteBackGround : WhiteBackGround {
                        w = UI_EXPR(GRID_W(8));
                    };
                    class TopBackGround : TopBackGround {
                        w = UI_EXPR(GRID_W(8) - 2*INFOBOX_PADDING_W);
                    };
                    class MainText : MainText
                    {
                        text = "ALT: 19";
                        onLoad = "uiNamespace setVariable ['DB_orlanHUD_alt_mainText', _this # 0]";
                        w = UI_EXPR(GRID_W(8));
                    };
                };
            };

            class StatusBox : InfoBox_Base
            {
                x = UI_EXPR(ANGLE_GROUP_X + INFOBOX_W + 3*GRID_W(8) + GRID_W(12) + GRID_W(1) + 4*GRID_W(0.5));
                y = UI_EXPR(ANGLE_GROUP_Y - INFOBOX_H);
                w = UI_EXPR(GRID_W(12));

                class controls : controls
                {
                    class WhiteBackGround : WhiteBackGround {
                        w = UI_EXPR(GRID_W(12));
                    };
                    class TopBackGround : TopBackGround {
                        w = UI_EXPR(GRID_W(12) - 2*INFOBOX_PADDING_W);
                    };
                    class MainText : MainText
                    {
                        text = "STATUS: OPERATIONAL";
                        onLoad = "uiNamespace setVariable ['DB_orlanHUD_status_mainText', _this # 0]";
                        w = UI_EXPR(GRID_W(12));
                    };
                };
            };

            class DirectionGroup : ctrlControlsGroupNoScrollBars
            {
                idc = -1;

                x = UI_EXPR((ANGLE_GROUP_X + INFOBOX_W + 3*GRID_W(8) + GRID_W(12) + GRID_W(1) + 4*GRID_W(0.5)) + GRID_W(12) / 2 - GRID_W(5) / 2 + GRID_W(1));
                y = UI_EXPR(ANGLE_GROUP_Y + GRID_H(1.2));
                w = UI_EXPR(GRID_W(5));
                h = UI_EXPR(GRID_H(6.8));

                class controls
                {
                    class Picture : ctrlStaticPicture
                    {
                        idc = -1;

                        text = "\orlan\pictures\12.paa";

                        onLoad = "uiNamespace setVariable ['DB_orlanHUD_direction_picture', _this # 0]";

                        x = 0;
                        y = 0;
                        w = UI_EXPR(GRID_W(5));
                        h = UI_EXPR(GRID_H(5));
                    };

                    class Box : InfoBox_Base
                    {
                        x = UI_EXPR(GRID_W(5) / 2 - INFOBOX_W / 2);
                        y = UI_EXPR(GRID_H(6.8) - INFOBOX_H);

                        class controls : controls
                        {
                            class WhiteBackGround : WhiteBackGround {};
                            class TopBackGround : TopBackGround {};
                            class MainText : MainText
                            {
                                text = "180";
                                onLoad = "uiNamespace setVariable ['DB_orlanHUD_direction_mainText', _this # 0]";
                            };
                        };
                    };
                };
            };

            class LaserDistanceBox : InfoBox_Base
            {
                x = UI_EXPR(ANGLE_GROUP_X + INFOBOX_W + GRID_W(1));
                y = UI_EXPR(ANGLE_GROUP_Y - INFOBOX_H  + INFOBOX_H + GRID_H(0.4));
                w = UI_EXPR(GRID_W(8));

                class controls : controls
                {
                    class WhiteBackGround : WhiteBackGround {
                        w = UI_EXPR(GRID_W(8));
                    };
                    class TopBackGround : TopBackGround {
                        w = UI_EXPR(GRID_W(8) - 2*INFOBOX_PADDING_W);
                    };
                    class MainText : MainText
                    {
                        onLoad = "uiNamespace setVariable ['DB_orlanHUD_laserDistance_mainText', _this # 0]";
                        text = "2100 м.";
                        w = UI_EXPR(GRID_W(8));
                    };
                };
            };

            class DroneSpeedBox : InfoBox_Base
            {
                x = UI_EXPR(ANGLE_GROUP_X + INFOBOX_W + GRID_W(8) + GRID_W(1) + GRID_W(0.5));
                y = UI_EXPR(ANGLE_GROUP_Y - INFOBOX_H  + INFOBOX_H + GRID_H(0.4));
                w = UI_EXPR(GRID_W(12));

                class controls : controls
                {
                    class WhiteBackGround : WhiteBackGround {
                        w = UI_EXPR(GRID_W(12));
                    };
                    class TopBackGround : TopBackGround {
                        w = UI_EXPR(GRID_W(12) - 2*INFOBOX_PADDING_W);
                    };
                    class MainText : MainText
                    {
                        onLoad = "uiNamespace setVariable ['DB_orlanHUD_droneSpeed_mainText', _this # 0]";
                        text = "СКОРОСТЬ: 120 КМ/Ч";
                        w = UI_EXPR(GRID_W(12));
                    };
                };
            };

            class PitchBox : InfoBox_Base
            {
                x = UI_EXPR(ANGLE_GROUP_X + INFOBOX_W + GRID_W(8) + GRID_W(12) + GRID_W(1) + 2*GRID_W(0.5));
                y = UI_EXPR(ANGLE_GROUP_Y - INFOBOX_H  + INFOBOX_H + GRID_H(0.4));
                w = UI_EXPR(GRID_W(8));

                class controls : controls
                {
                    class WhiteBackGround : WhiteBackGround {
                        w = UI_EXPR(GRID_W(8));
                    };
                    class TopBackGround : TopBackGround {
                        w = UI_EXPR(GRID_W(8) - 2*INFOBOX_PADDING_W);
                    };
                    class MainText : MainText
                    {
                        text = "ТАНГАЖ: 75 г.";
                        onLoad = "uiNamespace setVariable ['DB_orlanHUD_pitch_mainText', _this # 0]";
                        w = UI_EXPR(GRID_W(8));
                    };
                };
            };
        };
    };
};
