#pragma once

#include "Input/CarControls.hpp"
#include "Util/Logger.hpp"
#include "VehicleConfig.h"

#include <simpleini/SimpleIni.h>
#include <vector>
#include <string>

class ScriptSettings {
public:
    ScriptSettings();
    void SetFiles(const std::string &general, const std::string& controls, const std::string &wheel);
    void Read(CarControls* scriptControl);
    void SaveGeneral();
    void SaveController(CarControls* scriptControl) const;
    void SaveWheel() const;

    void SetVehicleConfig(VehicleConfig* cfg);
    VehicleConfig& operator()();
    bool ConfigActive();
    VehicleConfig* BaseConfig();

    bool Error() const;

    struct TimerParams {
        std::string Unit;
        float LimA;
        float LimB;
        float Tolerance;
    };

    // settings_general.ini parts
    // [MT_OPTIONS]
    struct {
        bool Enable = true;

        bool EngDamage = false;
        // H-Pattern
        bool EngStallH = true;
        bool EngStallS = false;
        bool EngBrake = false;
        bool EngLock = false;
        bool FinalGearRPMLimit = true;
    } MTOptions;

    // [GAMEPLAY_ASSISTS]
    struct {
        bool SimpleBike = false;
        bool HillGravity = false;
        bool AutoGear1 = false;
        bool AutoLookBack = false;
        bool ThrottleStart = false;
        bool DefaultNeutral = true;
        bool DisableAutostart = false;
        bool LeaveEngineRunning = false;
    } GameAssists;

    // [CUSTOM_STEERING]
    struct {
        // 0 Default, 1 Enhanced
        int Mode = 1;
        float CountersteerMult = 1.0f;
        // In Degrees
        float CountersteerLimit = 15.0f;
        bool NoReductionHandbrake = false;
        float Gamma = 1.0f;
        float CenterTime = 0.01f;
        float SteerTime = 0.01f;
        struct {
            bool Enable = true;
            float Sensitivity = 0.5f;
            bool DisableSteerAssist = false;
            bool DisableReduction = false;
        } Mouse;
    } CustomSteering;

    // [HUD]
    struct {
        bool Enable = true;
        bool Always = true;
        // Fonts:
        // 0 - Chalet London
        // 1 - Sign Painter
        // 2 - Slab Serif
        // 4 - Chalet Cologne
        // 7 - Pricedown
        int Font = 4;

        bool Outline = true;

        // Levels:
        // 0 - Debug
        // 1 - Info
        // 2 - Error/UI (LogLevel WARN)
        // 3 - None
        int NotifyLevel = INFO;

        struct {
            bool Enable = true;
            float XPos = 0.9525f;
            float YPos = 0.885f;
            float Size = 0.700f;
            int TopColorR = 255;
            int TopColorG = 63;
            int TopColorB = 63;
            int ColorR = 255;
            int ColorG = 255;
            int ColorB = 255;
        } Gear;

        struct {
            bool Enable = true;
            float XPos = 0.935f;
            float YPos = 0.885f;
            float Size = 0.700f;
            int ColorR = 255;
            int ColorG = 255;
            int ColorB = 255;
        } ShiftMode;

        struct {
            // can be kph, mph, or ms
            std::string Speedo = "kph";
            bool ShowUnit = true;
            bool UseDrivetrain = true;
            float XPos = 0.860f;
            float YPos = 0.885f;
            float Size = 0.700f;
            int ColorR = 255;
            int ColorG = 255;
            int ColorB = 255;
        } Speedo;

        struct {
            bool Enable = true;
            float Redline = 0.850f;

            float XPos = 0.120f;
            float YPos = 0.765f;
            float XSz = 0.140f;
            float YSz = 0.005f;

            int BgR = 0;
            int BgG = 0;
            int BgB = 0;
            int BgA = 128;

            int FgR = 255;
            int FgG = 255;
            int FgB = 255;
            int FgA = 255;

            int RedlineR = 255;
            int RedlineG = 92;
            int RedlineB = 0;
            int RedlineA = 255;

            int RevLimitR = 255;
            int RevLimitG = 0;
            int RevLimitB = 0;
            int RevLimitA = 255;

            int LaunchControlStagedR = 255;
            int LaunchControlStagedG = 255;
            int LaunchControlStagedB = 0;
            int LaunchControlStagedA = 255;

            int LaunchControlActiveR = 255;
            int LaunchControlActiveG = 127;
            int LaunchControlActiveB = 0;
            int LaunchControlActiveA = 255;
        } RPMBar;

        struct {
            bool Enable = true;
            bool Always = false;
            float ImgXPos = 0.22f;
            float ImgYPos = 0.80f;
            float ImgSize = 0.05f;

            float PedalXPos = 0.22f;
            float PedalYPos = 0.90f;
            float PedalXSz = 0.04f;
            float PedalYSz = 0.10f;
            float PedalXPad = 0.0f;
            float PedalYPad = 0.0f;
            int PedalBgA = 92;

            int PedalThrottleR = 0;
            int PedalThrottleG = 255;
            int PedalThrottleB = 0;
            int PedalThrottleA = 255;

            int PedalBrakeR = 255;
            int PedalBrakeG = 0;
            int PedalBrakeB = 0;
            int PedalBrakeA = 255;

            int PedalClutchR = 0;
            int PedalClutchG = 0;
            int PedalClutchB = 255;
            int PedalClutchA = 255;

            struct {
                bool Enable = false;

                float XPos = 0.500f;
                float YPos = 0.025f;
                float XSz = 0.25f;
                float YSz = 0.05f;

                int BgR = 0;
                int BgG = 0;
                int BgB = 0;
                int BgA = 128;

                int FgR = 255;
                int FgG = 255;
                int FgB = 255;
                int FgA = 255;

                int LimitR = 255;
                int LimitG = 0;
                int LimitB = 0;
                int LimitA = 255;
            } FFB;
        } Wheel;

        struct {
            bool Enable = false;
            float XPos = 0.500f;
            float YPos = 0.035f;
            float Size = 1.000f;

            bool Lite = false;
            float TxtVOffset = 0.0f;
            float TxtSzMod = 1.0f;
        } DashIndicators;

        struct {
            bool Enable = true;
            float XPos = 0.500f;
            float YPos = 0.300f;
            float Size = 0.050f;
        } DsProt;

        struct {
            bool Enable = false;
            float XPos = 0.5f;
            float YPos = 0.95f;
            float XSz = 0.5f;
            float YSz = 0.05f;
            float MarkerXSz = 0.020f;

            int BgR = 0;
            int BgG = 0;
            int BgB = 0;
            int BgA = 128;

            int FgR = 255;
            int FgG = 255;
            int FgB = 255;
            int FgA = 255;
        } MouseSteering;
    } HUD;

    // [CONTROLLER]
    struct {
        int HoldTimeMs = 250;
        int MaxTapTimeMs = 200;
        float TriggerValue = 0.75f;

        bool CustomDeadzone = false;
        int DeadzoneRightThumb = XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE;
        int DeadzoneLeftThumb = XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE;

        bool ToggleEngine = false;

        bool BlockCarControls = true;
        bool IgnoreShiftsUI = true;
        bool BlockHShift = true;

        //long ShiftUpBlocks = -1;
        //long ShiftDownBlocks = -1;
        //long ClutchBlocks = -1;

        struct {
            bool Enable = false;
            //long ShiftUpBlocks = -1;
            //long ShiftDownBlocks = -1;
            //long ClutchBlocks = -1;
        } Native;
    } Controller;

    // [MISC]
    struct {
        bool UDPTelemetry = true;
        std::string UDPAddress = "127.0.0.1";
        int UDPPort = 20777;

        bool DashExtensions = true;
        bool SyncAnimations = true;

        bool HidePlayerInFPV = false;
        bool HideWheelInFPV = false;

        bool SaveFullConfig = true;
    } Misc;

    // [UPDATE]
    struct {
        bool EnableUpdate = true;
        std::string IgnoredVersion = "v0.0.0";
    } Update;

    // [DEBUG]
    struct {
        int LogLevel = INFO; // Only load
        bool CancelAnimOnUnload = false; // Only load
        bool DisplayInfo = false;
        bool DisplayGearingInfo = false;
        bool DisplayWheelInfo = false;
        bool DisplayMaterialInfo = false;
        bool DisplayTractionInfo = false;
        bool DisplayNPCInfo = false;
        bool ShowAdvancedFFBOptions = false;
        bool DisableRPMLimit = false;

        bool DisableInputDetect = false;
        bool DisablePlayerHide = false;
        bool DisableNPCGearbox = false;
        bool DisableNPCBrake = false;

        struct {
            bool EnableTimers = false;
            std::vector<TimerParams> Timers{
                { "kph", 0.0f, 100.0f, 0.1f },
                { "mph", 0.0f,  60.0f, 0.1f }
            };
            struct {
                bool Enable = false;
                float PosX = 0.075f;
                float PosY = 0.125f;
                float Size = 0.200f;
            } GForce;
        } Metrics;
    } Debug;

    // settings_wheel.ini parts
    struct {
        // [OPTIONS]
        struct {
            bool Enable = true;
            bool LogiLEDs = false;
            bool HPatternKeyboard = false;
            bool UseShifterForAuto = false;
        } Options;

        // [INPUT_DEVICES]
        struct {
            std::vector<GUID> RegisteredGUIDs;
            std::vector<Device> RegisteredDevices;
        } InputDevices;

        // [FORCE_FEEDBACK]
        struct {
            // Global options
            bool Enable = true;

            float SATAmpMult = 1.00f;

            int DamperMax = 100;
            int DamperMin = 40;
            float DamperMinSpeed = 6.4f; // TargetSpeed in m/s

            float DetailMult = 4.0f;
            int DetailLim = 5000;
            int DetailMAW = 3;
            float CollisionMult = 2.5f;

            int AntiDeadForce = 0;
            std::string LUTFile;

            // Ground physics
            int FFBProfile = 0;
            float ResponseCurve = 1.0f;
            float SlipOptMin = 7.5f;        // Advanced
            float SlipOptMinMult = 1.6f;    // Advanced
            float SlipOptMax = 25.0f;       // Advanced
            float SlipOptMaxMult = 1.0f;    // Advanced

            // Alternative/legacy
            float SATFactor = 0.80f;
            float Gamma = 0.75f;
            float MaxSpeed = 80.0f;
        } FFB;

        // [STEER]
        struct {
            float AngleMax = 900.0f;
            float AngleCar = 720.0f;
            float AngleBike = 180.0f;
            float AngleBoat = 360.0f;
            float Gamma = 1.0f;
            float AntiDeadZone = 0.25f;
            float DeadZone = 0.0f;
            float DeadZoneOffset = 0.0f;
            int Min = -1;
            int Max = -1;
        } Steering;

        // [THROTTLE]
        struct {
            float Gamma = 1.0f;
            float AntiDeadZone = 0.25f;
            int Min = -1;
            int Max = -1;
        } Throttle;

        // [BRAKE]
        struct {
            float Gamma = 1.0f;
            float AntiDeadZone = 0.25f;
            int Min = -1;
            int Max = -1;
        } Brake;

        // [CLUTCH]
        struct {
            int Min = -1;
            int Max = -1;
        } Clutch;

        // [HANDBRAKE_ANALOG]
        struct {
            int Min = -1;
            int Max = -1;
        } HandbrakeA;
    } Wheel;

    // Methods
    /*
     *  Checks if GUID already exists and returns device index
     *  otherwise appends GUID and returns new device index
     */
    ptrdiff_t SteeringAppendDevice(const GUID & dev_guid, const std::string& dev_name);
    int GUIDToDeviceIndex(GUID guid);
    std::string GUIDToDeviceName(GUID guid);

    void SteeringSaveAxis(const std::string &confTag, ptrdiff_t index, const std::string &axis, int minVal, int maxVal);
    void SteeringSaveButton(const std::string &confTag, ptrdiff_t index, int button);
    void KeyboardSaveKey(const std::string &confTag, const std::string &key);
    void ControllerSaveButton(const std::string &confTag, const std::string &button);
    void LControllerSaveButton(const std::string & confTag, int button);
    void SteeringAddWheelToKey(const std::string & conftag, ptrdiff_t index, int button, const std::string & keyName);
    bool SteeringClearWheelToKey(const std::string& assignment);
private:
    void parseSettingsGeneral();
    void parseSettingsControls(CarControls* scriptControl);
    void parseSettingsWheel(CarControls *scriptControl);

    // Just looks up which GUID corresponds with what number and returns the GUID.
    GUID DeviceIndexToGUID(int device, std::vector<GUID> guids);

    template<typename T>
    CarControls::SInput<T> parseWheelItem(CSimpleIniA& ini, const char* section, T defaultValue, const char* name = nullptr);

    CarControls::SInput<int> parseKeyboardItem(CSimpleIniA& ini, const char* key, const char* defaultValue, const char* name = nullptr);

    template<typename T>
    CarControls::SInput<T> parseControllerItem(CSimpleIniA& ini, const char* key, T defaultValue, const char* name, const char* description);

    int nDevices = 0;
    std::string settingsGeneralFile;
    std::string settingsControlsFile;
    std::string settingsWheelFile;
    std::string settingsMenuFile;
    VehicleConfig baseConfig;
    mutable bool mError{ false };
};
