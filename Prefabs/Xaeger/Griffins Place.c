static Object SpawnObject(string type, vector position, vector orientation, float scale = 1.0)
{
    Object obj;
    if (type.Contains(".p3d")) {
        obj = GetGame().CreateStaticObjectUsingP3D(type, position, orientation, scale, false);
    } else {        
        obj = GetGame().CreateObjectEx(type, position, ECE_SETUP | ECE_CREATEPHYSICS | ECE_NOLIFETIME | ECE_NOPERSISTENCY_WORLD | ECE_NOPERSISTENCY_CHAR);
    }

    if (!obj) {
        Error("Failed to create object " + type);
        return null;
    }

    obj.SetPosition(position);
    obj.SetOrientation(orientation);
    obj.SetOrientation(obj.GetOrientation());
    obj.SetScale(scale);
    obj.Update();
	obj.SetAffectPathgraph(true, false);
	if (obj.CanAffectPathgraph()) {
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, obj);
    } 

    return obj;
}

// Paste anything below this line into the bottom of your 'void main()' function


// Created Objects
SpawnObject("Land_Misc_FireBarrel_Red", "9538.484375 175.296951 11769.765625", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("Land_House_1W06", "9530.405273 177.772919 11750.144531", "73.518394 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Misc_WoodReserve", "9516.521484 174.967667 11747.526367", "-179.087463 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_VilVar2_4_2", "9540.255859 174.599869 11772.025391", "-157.999985 0.000000 0.000000", 0.999999);
SpawnObject("StaticObj_Wall_VilVar2_4_2", "9540.588867 174.599899 11765.979492", "-44.999973 0.000000 0.000000", 1);
SpawnObject("StaticObj_Slum_Roof4", "9538.744141 175.092453 11769.625000", "-170.999924 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_SofaCorner", "9537.452148 174.503632 11770.313477", "-179.999878 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_metalcrate", "9541.203125 174.090103 11768.000977", "9.000011 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_postel_manz_kov", "9531.276367 176.699051 11750.881836", "-107.999855 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Misc_Table_Market", "9540.269531 174.519470 11771.047852", "-162.000092 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_radio_b", "9539.621094 174.982101 11771.156250", "-144.000076 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_canister_DZ", "9541.305664 174.588135 11768.125977", "-63.000031 0.000000 0.000000", 1);
SpawnObject("StaticObj_Misc_TirePile", "9541.168945 178.253937 11769.388672", "18.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_ToolTrolley_02_F", "9536.291016 174.569519 11768.458008", "-81.000038 0.000000 0.000000", 1);
SpawnObject("StaticObj_EngineCrane_01_F", "9539.912109 175.108429 11766.258789", "45.000023 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_carpet_big", "9525.027344 174.871002 11770.860352", "92.815552 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Furniture_Couch_Beige84x213x75_DZ", "9530.300781 176.854477 11745.916016", "81.000038 -0.000000 -0.000000", 1);


// Uncomment if you want to export loot from newly added buildings
// Position, Radius (increase if you have a larger map than Chernarus)
// GetCEApi().ExportProxyData(Vector(7500, GetGame().SurfaceY(7500, 7500), 7500), 20000);
