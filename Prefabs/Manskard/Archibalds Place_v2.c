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
SpawnObject("StaticObj_Misc_Bench9", "9146.119141 261.363159 9407.443359", "53.999981 -0.000000 -0.000000", 1);
SpawnObject("Land_Misc_FireBarrel_Green", "9147.631836 262.401703 9408.179688", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Misc_SupplyBox1_DE", "9156.340820 261.372253 9408.884766", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("StaticObj_Wall_Wood5_4", "9139.754883 265.162292 9403.087891", "0.000005 -90.000000 3.495619", 1.5);
SpawnObject("StaticObj_Ruin_Corner1", "9147.307617 267.046082 9396.309570", "2.581259 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Ruin_Corner2", "9139.678711 266.231689 9401.905273", "92.719017 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Bridge_Wood2", "9148.073242 266.645691 9399.356445", "0.721961 0.000000 -0.000000", 0.6);
SpawnObject("Land_Bilboard_likery_bardak", "9139.892578 261.555725 9393.600586", "0.000116 -6.984811 -0.000014", 1);
SpawnObject("StaticObj_Wall_Wood5_4", "9148.347656 265.141144 9397.977539", "-89.999992 -90.000000 -176.504379", 1.5);
SpawnObject("StaticObj_Bridge_Wood2", "9142.772461 266.645691 9402.587891", "90.000000 0.000000 0.000000", 0.6);
SpawnObject("StaticObj_Wall_WoodVil_4_pole", "9142.328125 266.241119 9400.506836", "0.000000 -0.000000 -0.000000", 3);
SpawnObject("StaticObj_Road_Sidewalk_Stairs", "9141.117188 266.400146 9397.510742", "-176.539810 0.000000 -0.000000", 1);
SpawnObject("StaticObj_Bridge_Wood2", "9144.668945 266.645691 9399.404297", "0.721961 0.000000 -0.000000", 0.6);
SpawnObject("StaticObj_Bridge_Wood2", "9138.490234 267.475922 9397.558594", "0.721961 0.000000 -0.000000", 0.4);
SpawnObject("StaticObj_Wall_WoodVil_4_pole", "9137.201172 266.050568 9405.357422", "0.000000 -0.000000 -0.000000", 3);
SpawnObject("StaticObj_Slum_Roof4", "9155.265625 262.483551 9406.365234", "162.000092 0.000000 -0.000000", 1);
SpawnObject("Land_Misc_Table_Market_Spawn", "9154.437500 261.563629 9404.350586", "-17.999960 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_Couch_Beige84x213x75_DZ", "9146.142578 261.469879 9397.596680", "90.000000 0.000000 0.000000", 1);
SpawnObject("Land_Misc_Table_Market_Spawn", "9156.752930 261.436829 9405.608398", "-35.999992 0.000000 0.000000", 1);
SpawnObject("StaticObj_Misc_Bench9", "9148.295898 261.363007 9406.390625", "-9.000069 0.000000 0.000000", 1);
SpawnObject("StaticObj_Misc_WoodenCrate_3x", "9152.927734 261.773315 9407.560547", "0.000000 -0.000000 -0.000000", 1);
SpawnObject("Land_Shed_W6", "9173.336914 263.177032 9389.420898", "67.256714 -0.000000 -0.000000", 0.998113);
SpawnObject("Land_Shed_W6", "9166.191406 262.477783 9400.172852", "45.000023 -0.000000 -0.000000", 0.996021);
SpawnObject("StaticObj_Wall_Tin7_Blue_4", "9136.294922 262.501984 9397.155273", "92.999992 0.000000 0.000000", 1);
SpawnObject("StaticObj_Furniture_lobby_chair", "9145.002930 261.561768 9395.744141", "154.603592 0.000000 -0.000000", 1);


// Uncomment if you want to export loot from newly added buildings
// Position, Radius (increase if you have a larger map than Chernarus)
// GetCEApi().ExportProxyData(Vector(7500, GetGame().SurfaceY(7500, 7500), 7500), 20000);
