<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="13008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="NI.SortType" Type="Int">3</Property>
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Support" Type="Folder">
			<Item Name="App EXE.ico" Type="Document" URL="../App EXE.ico"/>
			<Item Name="Parse Digital Module.vi" Type="VI" URL="../Parse Digital Module.vi"/>
			<Item Name="Draw Simple Skeleton Picture.vi" Type="VI" URL="../Draw Simple Skeleton Picture.vi"/>
			<Item Name="Interpolate RGB Color.vi" Type="VI" URL="../Interpolate RGB Color.vi"/>
			<Item Name="Playback Controls.vi" Type="VI" URL="../Playback Controls.vi"/>
			<Item Name="Initialize Camera and CheckList.vi" Type="VI" URL="../Initialize Camera and CheckList.vi"/>
			<Item Name="Open Playback Panel.vi" Type="VI" URL="../Open Playback Panel.vi"/>
			<Item Name="Build Simple Skeleton Data.vi" Type="VI" URL="../Build Simple Skeleton Data.vi"/>
		</Item>
		<Item Name="Dashboard Main.vi" Type="VI" URL="../Dashboard Main.vi"/>
		<Item Name="624 Ball Detection.vi" Type="VI" URL="../../Ball Detection/624 Ball Detection.vi"/>
		<Item Name="Sorted Particle Report.vi" Type="VI" URL="../../Ball Detection/Sorted Particle Report.vi"/>
		<Item Name="Fit Circle to Find Ball.vi" Type="VI" URL="../../Ball Detection/Fit Circle to Find Ball.vi"/>
		<Item Name="Create Annulus from Rectangle.vi" Type="VI" URL="../../Ball Detection/Create Annulus from Rectangle.vi"/>
		<Item Name="Predict Search Rectangle from Particle.vi" Type="VI" URL="../../Ball Detection/Predict Search Rectangle from Particle.vi"/>
		<Item Name="Process Image for Balls.vi" Type="VI" URL="../../Ball Detection/Process Image for Balls.vi"/>
		<Item Name="Label Particles.vi" Type="VI" URL="../../Ball Detection/Label Particles.vi"/>
		<Item Name="Compare Rects.vi" Type="VI" URL="../../Ball Detection/Compare Rects.vi"/>
		<Item Name="Normalized to Scored.vi" Type="VI" URL="../../Ball Detection/Normalized to Scored.vi"/>
		<Item Name="Circle Coverage Score.vi" Type="VI" URL="../../Ball Detection/Circle Coverage Score.vi"/>
		<Item Name="Score and Sort Objects.vi" Type="VI" URL="../../Ball Detection/Score and Sort Objects.vi"/>
		<Item Name="Score and Rank Objects.vi" Type="VI" URL="../../Ball Detection/Score and Rank Objects.vi"/>
		<Item Name="Calibration Helper.vi" Type="VI" URL="../../Ball Detection/Calibration Helper.vi"/>
		<Item Name="Send Vision Packet.vi" Type="VI" URL="../Send Vision Packet.vi"/>
		<Item Name="Vision Packet.ctl" Type="VI" URL="../../Common Code/Vision Packet.ctl"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="IMAQ Create" Type="VI" URL="/&lt;vilib&gt;/vision/Basics.llb/IMAQ Create"/>
				<Item Name="IMAQ Image.ctl" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/IMAQ Image.ctl"/>
				<Item Name="Image Type" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/Image Type"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="Dflt Data Dir.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Dflt Data Dir.vi"/>
				<Item Name="WPI_DriverStationDigitalData.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/DriverStation/WPI_DriverStationDigitalData.ctl"/>
				<Item Name="IMAQ Clear Overlay" Type="VI" URL="/&lt;vilib&gt;/vision/Overlay.llb/IMAQ Clear Overlay"/>
				<Item Name="WPI_JoystickDeviceDataRaw.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Joystick/WPI_JoystickDeviceDataRaw.ctl"/>
				<Item Name="WPI_CameraDecodeJPEGString.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Camera/WPI_CameraDecodeJPEGString.vi"/>
				<Item Name="SkeletonTrackState.ctl" Type="VI" URL="/&lt;vilib&gt;/addons/Kinect/SkeletonTrackState.ctl"/>
				<Item Name="Vector4.ctl" Type="VI" URL="/&lt;vilib&gt;/addons/Kinect/Vector4.ctl"/>
				<Item Name="SkeletonVertexTrackState.ctl" Type="VI" URL="/&lt;vilib&gt;/addons/Kinect/SkeletonVertexTrackState.ctl"/>
				<Item Name="LVBoundsTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVBoundsTypeDef.ctl"/>
				<Item Name="Map To Depth Space.vi" Type="VI" URL="/&lt;vilib&gt;/addons/Kinect/Map To Depth Space.vi"/>
				<Item Name="Scale Skeleton Points to Display.vi" Type="VI" URL="/&lt;vilib&gt;/addons/Kinect/Scale Skeleton Points to Display.vi"/>
				<Item Name="Make Skeleton Connectors.vi" Type="VI" URL="/&lt;vilib&gt;/addons/Kinect/Make Skeleton Connectors.vi"/>
				<Item Name="Draw Multiple Lines.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Draw Multiple Lines.vi"/>
				<Item Name="Hilite Color.vi" Type="VI" URL="/&lt;vilib&gt;/picture/pictutil.llb/Hilite Color.vi"/>
				<Item Name="Draw Circle by Radius.vi" Type="VI" URL="/&lt;vilib&gt;/picture/pictutil.llb/Draw Circle by Radius.vi"/>
				<Item Name="WPI_JoystickScaleTo100PlusMinRange.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Joystick/WPI_JoystickScaleTo100PlusMinRange.vi"/>
				<Item Name="WPI_CameraRead MJPG.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Camera/WPI_CameraRead MJPG.vi"/>
				<Item Name="WPI_CameraIssue HTTP Request with Authentication.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Camera/WPI_CameraIssue HTTP Request with Authentication.vi"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
				<Item Name="WPI_CameraERRAccountProblem.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Camera/WPI_CameraERRAccountProblem.vi"/>
				<Item Name="WPI_UtilitiesFRC Build Error.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Utilities/WPI_UtilitiesFRC Build Error.vi"/>
				<Item Name="WPI_CameraERRFailedComm.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Camera/WPI_CameraERRFailedComm.vi"/>
				<Item Name="WPI_CameraImageSize.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Camera/WPI_CameraImageSize.ctl"/>
				<Item Name="Get Tab Control Refs.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Get Tab Control Refs.vi"/>
				<Item Name="Bind Controls to SmartDashboard.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Bind Controls to SmartDashboard.vi"/>
				<Item Name="NT Event Type.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/NT Event Type.ctl"/>
				<Item Name="Protocol Operations.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Protocol Operations.ctl"/>
				<Item Name="Field Data.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Field Data.ctl"/>
				<Item Name="Field Type.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Field Type.ctl"/>
				<Item Name="Sequence.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Sequence.ctl"/>
				<Item Name="Prepare Table Name.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Prepare Table Name.vi"/>
				<Item Name="Convert Variant to NT Cluster.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Convert Variant to NT Cluster.vi"/>
				<Item Name="NT Write Generic Value.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/NT Write Generic Value.vi"/>
				<Item Name="Make Table Operation.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Make Table Operation.ctl"/>
				<Item Name="NT Globals.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/NT Globals.vi"/>
				<Item Name="Table Manager.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Table Manager.vi"/>
				<Item Name="Field ID.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Field ID.ctl"/>
				<Item Name="String Matches Pattern.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/String Matches Pattern.vi"/>
				<Item Name="Tokenize Path.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Tokenize Path.vi"/>
				<Item Name="Prepare Pattern.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Prepare Pattern.vi"/>
				<Item Name="Write Value Core.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Write Value Core.vi"/>
				<Item Name="Field Data Manager.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Field Data Manager.vi"/>
				<Item Name="Build Entry Assign Buffer.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Build Entry Assign Buffer.vi"/>
				<Item Name="Convert NT Types.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Convert NT Types.vi"/>
				<Item Name="Convert String to NT String Buffer.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Convert String to NT String Buffer.vi"/>
				<Item Name="Convert NT Boolean to LV String.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Convert NT Boolean to LV String.vi"/>
				<Item Name="Convert String to NT Boolean Array Buffer.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Convert String to NT Boolean Array Buffer.vi"/>
				<Item Name="Convert String to NT Numeric Array Buffer.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Convert String to NT Numeric Array Buffer.vi"/>
				<Item Name="Convert String to NT String Array Buffer.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Convert String to NT String Array Buffer.vi"/>
				<Item Name="Update Other Clients.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Update Other Clients.vi"/>
				<Item Name="Manage Connection List.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Manage Connection List.vi"/>
				<Item Name="Manage Dirty Field ID List.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Manage Dirty Field ID List.vi"/>
				<Item Name="NT Client.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/NT Client.vi"/>
				<Item Name="Handle Dirty Elements.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Handle Dirty Elements.vi"/>
				<Item Name="Handle Dirty Fields for a Connection.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Handle Dirty Fields for a Connection.vi"/>
				<Item Name="Build NT Data Update for Cluster.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Build NT Data Update for Cluster.vi"/>
				<Item Name="Build NT Field ID Buffer.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Build NT Field ID Buffer.vi"/>
				<Item Name="Build NT Ping Buffer.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Build NT Ping Buffer.vi"/>
				<Item Name="Process one Action.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Process one Action.vi"/>
				<Item Name="Parse NT Data.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Parse NT Data.vi"/>
				<Item Name="Parse NT Boolean.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Parse NT Boolean.vi"/>
				<Item Name="Parse NT Dbl.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Parse NT Dbl.vi"/>
				<Item Name="Parse NT String.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Parse NT String.vi"/>
				<Item Name="Parse NT Boolean Array.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Parse NT Boolean Array.vi"/>
				<Item Name="Parse NT Numeric Array.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Parse NT Numeric Array.vi"/>
				<Item Name="Parse NT String Array.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Parse NT String Array.vi"/>
				<Item Name="Update Entry.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Update Entry.vi"/>
				<Item Name="Compare Seq Numbers.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Compare Seq Numbers.vi"/>
				<Item Name="Convert NT Cluster to Variant.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Convert NT Cluster to Variant.vi"/>
				<Item Name="NT Read and Format Entries as Tree.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/NT Read and Format Entries as Tree.vi"/>
				<Item Name="Prepare Tree Entries.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Prepare Tree Entries.vi"/>
				<Item Name="NT Format Generic  to String.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/NT Format Generic  to String.vi"/>
				<Item Name="NT Read Name Cache.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/NT Read Name Cache.vi"/>
				<Item Name="Report Read Error.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Report Read Error.vi"/>
				<Item Name="NT Read String.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/NT Read String.vi"/>
				<Item Name="NT Write String.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/NT Write String.vi"/>
				<Item Name="NT Write Name Cache.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/NT Write Name Cache.vi"/>
				<Item Name="NT Write Number.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/NT Write Number.vi"/>
				<Item Name="NT Read Number.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/NT Read Number.vi"/>
				<Item Name="eventvkey.ctl" Type="VI" URL="/&lt;vilib&gt;/event_ctls.llb/eventvkey.ctl"/>
				<Item Name="WPI_UtilitiesGetTreeIOName.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Utilities/WPI_UtilitiesGetTreeIOName.vi"/>
				<Item Name="DS_Mode_Simulation_Global.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Simulation/DS_Mode_Simulation_Global.vi"/>
				<Item Name="imagedata.ctl" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/imagedata.ctl"/>
				<Item Name="Unflatten Pixmap.vi" Type="VI" URL="/&lt;vilib&gt;/picture/pixmap.llb/Unflatten Pixmap.vi"/>
				<Item Name="IMAQ ArrayToColorImage" Type="VI" URL="/&lt;vilib&gt;/vision/Basics.llb/IMAQ ArrayToColorImage"/>
				<Item Name="Color (U64)" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/Color (U64)"/>
				<Item Name="NI_LVConfig.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/config.llb/NI_LVConfig.lvlib"/>
				<Item Name="Usage Statistics.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Usage Statistics.vi"/>
				<Item Name="Get Last Path Segment.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Get Last Path Segment.vi"/>
				<Item Name="Space Constant.vi" Type="VI" URL="/&lt;vilib&gt;/dlg_ctls.llb/Space Constant.vi"/>
				<Item Name="Check if File or Folder Exists.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/libraryn.llb/Check if File or Folder Exists.vi"/>
				<Item Name="NI_FileType.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/lvfile.llb/NI_FileType.lvlib"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="NI_PackedLibraryUtility.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/LVLibp/NI_PackedLibraryUtility.lvlib"/>
				<Item Name="8.6CompatibleGlobalVar.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/config.llb/8.6CompatibleGlobalVar.vi"/>
				<Item Name="Make All Variables Temporary.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Make All Variables Temporary.vi"/>
				<Item Name="WPI_CameraSettings Read MJPG.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Camera/WPI_CameraSettings Read MJPG.ctl"/>
				<Item Name="Transmitted Bytes.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Transmitted Bytes.vi"/>
				<Item Name="Compute Delta.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/Compute Delta.vi"/>
				<Item Name="NT Read String Array.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/NT Read String Array.vi"/>
				<Item Name="Set Pen State.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Set Pen State.vi"/>
				<Item Name="Draw Arc.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Draw Arc.vi"/>
				<Item Name="SD Read Name Cache.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/SD Read Name Cache.vi"/>
				<Item Name="Color to RGB.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/colorconv.llb/Color to RGB.vi"/>
				<Item Name="RGB to Color.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/colorconv.llb/RGB to Color.vi"/>
				<Item Name="IMAQ AVI2 Codec Path.ctl" Type="VI" URL="/&lt;vilib&gt;/vision/Avi.llb/IMAQ AVI2 Codec Path.ctl"/>
				<Item Name="IMAQ AVI2 Get Codec Names" Type="VI" URL="/&lt;vilib&gt;/vision/Avi.llb/IMAQ AVI2 Get Codec Names"/>
				<Item Name="IMAQ AVI2 Refnum.ctl" Type="VI" URL="/&lt;vilib&gt;/vision/Avi.llb/IMAQ AVI2 Refnum.ctl"/>
				<Item Name="IMAQ AVI2 Create" Type="VI" URL="/&lt;vilib&gt;/vision/Avi.llb/IMAQ AVI2 Create"/>
				<Item Name="System Directory Type.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/sysdir.llb/System Directory Type.ctl"/>
				<Item Name="Get System Directory.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/sysdir.llb/Get System Directory.vi"/>
				<Item Name="IMAQ AVI2 Write Frame" Type="VI" URL="/&lt;vilib&gt;/vision/Avi.llb/IMAQ AVI2 Write Frame"/>
				<Item Name="IMAQ AVI2 Close" Type="VI" URL="/&lt;vilib&gt;/vision/Avi.llb/IMAQ AVI2 Close"/>
				<Item Name="IMAQ AVI2 Open" Type="VI" URL="/&lt;vilib&gt;/vision/Avi.llb/IMAQ AVI2 Open"/>
				<Item Name="IMAQ AVI2 Read Frame" Type="VI" URL="/&lt;vilib&gt;/vision/Avi.llb/IMAQ AVI2 Read Frame"/>
				<Item Name="Initialize Mouse.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/inputDevices.llb/Initialize Mouse.vi"/>
				<Item Name="errorList.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/inputDevices.llb/errorList.vi"/>
				<Item Name="Acquire Input Data.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/inputDevices.llb/Acquire Input Data.vi"/>
				<Item Name="joystickAcquire.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/inputDevices.llb/joystickAcquire.vi"/>
				<Item Name="keyboardAcquire.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/inputDevices.llb/keyboardAcquire.vi"/>
				<Item Name="mouseAcquire.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/inputDevices.llb/mouseAcquire.vi"/>
				<Item Name="System Exec.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/system.llb/System Exec.vi"/>
				<Item Name="WPI_DashboardNT Log FieldName Substitutions.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardNT Log FieldName Substitutions.vi"/>
				<Item Name="WPI_DashboardVIdeo Path for Read.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardVIdeo Path for Read.vi"/>
				<Item Name="WPI_DashboardSD Updates.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardSD Updates.vi"/>
				<Item Name="WPI_DashboardUnpack DB data.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardUnpack DB data.vi"/>
				<Item Name="WPI_DashboardConvert to Log Format.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardConvert to Log Format.vi"/>
				<Item Name="WPI_DashboardRetrieve NetworkTables.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardRetrieve NetworkTables.vi"/>
				<Item Name="WPI_DashboardLog file path.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardLog file path.vi"/>
				<Item Name="WPI_DashboardLog NetworkTables.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardLog NetworkTables.vi"/>
				<Item Name="WPI_DashboardDecode Status Byte.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardDecode Status Byte.vi"/>
				<Item Name="WPI_DashboardNT Log FieldName Cache.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardNT Log FieldName Cache.vi"/>
				<Item Name="WPI_DashboardSeek to Scrub Time.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardSeek to Scrub Time.vi"/>
				<Item Name="WPI_DashboardNTL FF to New Position.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardNTL FF to New Position.vi"/>
				<Item Name="WPI_DashboardNT Log FieldName Filter.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardNT Log FieldName Filter.vi"/>
				<Item Name="WPI_DashboardGet All Users Directory.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardGet All Users Directory.vi"/>
				<Item Name="WPI_DashboardNTL Header Type.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardNTL Header Type.ctl"/>
				<Item Name="WPI_DashboardPlay Operation.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardPlay Operation.ctl"/>
				<Item Name="WPI_DashboardAdd File Length.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardAdd File Length.vi"/>
				<Item Name="WPI_DashboardDelete Videos.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardDelete Videos.vi"/>
				<Item Name="WPI_DashboardEnsure File Extension.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardEnsure File Extension.vi"/>
				<Item Name="WPI_DashboardRename Videos.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardRename Videos.vi"/>
				<Item Name="WPI_DashboardLogging Global.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardLogging Global.vi"/>
				<Item Name="WPI_DashboardDStoPCPacketTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardDStoPCPacketTypeDef.ctl"/>
				<Item Name="IMAQ Write JPEG File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write JPEG File 2"/>
				<Item Name="IMAQ Write TIFF File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write TIFF File 2"/>
				<Item Name="IMAQ Write PNG File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write PNG File 2"/>
				<Item Name="IMAQ Write JPEG2000 File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write JPEG2000 File 2"/>
				<Item Name="IMAQ Write Image And Vision Info File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write Image And Vision Info File 2"/>
				<Item Name="IMAQ Write BMP File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write BMP File 2"/>
				<Item Name="IMAQ Write File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write File 2"/>
				<Item Name="WPI_DashboardSave DB Images.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardSave DB Images.vi"/>
				<Item Name="WPI_DashboardUpdate Table Values.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Dashboard/WPI_DashboardUpdate Table Values.vi"/>
				<Item Name="NI_Vision_Development_Module.lvlib" Type="Library" URL="/&lt;vilib&gt;/vision/NI_Vision_Development_Module.lvlib"/>
				<Item Name="Particle Parameters" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/Particle Parameters"/>
				<Item Name="IMAQ GetImageSize" Type="VI" URL="/&lt;vilib&gt;/vision/Basics.llb/IMAQ GetImageSize"/>
				<Item Name="IMAQ Overlay Rectangle" Type="VI" URL="/&lt;vilib&gt;/vision/Overlay.llb/IMAQ Overlay Rectangle"/>
				<Item Name="IMAQ Overlay Text" Type="VI" URL="/&lt;vilib&gt;/vision/Overlay.llb/IMAQ Overlay Text"/>
				<Item Name="SD Read Number.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/SD Read Number.vi"/>
				<Item Name="Image Unit" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/Image Unit"/>
				<Item Name="IMAQ GetImageInfo" Type="VI" URL="/&lt;vilib&gt;/vision/Basics.llb/IMAQ GetImageInfo"/>
				<Item Name="SD Read Boolean.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/SD Read Boolean.vi"/>
				<Item Name="SD Read String.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/Network Tables/SD Read String.vi"/>
				<Item Name="Draw Rectangle.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Draw Rectangle.vi"/>
				<Item Name="PCT Pad String.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/PCT Pad String.vi"/>
				<Item Name="Draw Text in Rect.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Draw Text in Rect.vi"/>
				<Item Name="Get Text Rect.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Get Text Rect.vi"/>
				<Item Name="Draw Text at Point.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Draw Text at Point.vi"/>
				<Item Name="Empty Picture" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Empty Picture"/>
			</Item>
			<Item Name="nivissvc.dll" Type="Document" URL="nivissvc.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
			<Item Name="nivision.dll" Type="Document" URL="nivision.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
			<Item Name="lvinput.dll" Type="Document" URL="/&lt;resource&gt;/lvinput.dll"/>
			<Item Name="624WPI_DashboardReceive DS Packet.vi" Type="VI" URL="../624WPI_DashboardReceive DS Packet.vi"/>
			<Item Name="Omni Packet.ctl" Type="VI" URL="../../Common Code/Dashboard UDP/Omni Packet.ctl"/>
			<Item Name="Send Omni Packet.vi" Type="VI" URL="../Send Omni Packet.vi"/>
			<Item Name="Goal Info.ctl" Type="VI" URL="../../Common Code/Goal Info.ctl"/>
			<Item Name="Compute DistanceToTarget.vi" Type="VI" URL="../../Vision/Goal Detection/Compute DistanceToTarget.vi"/>
			<Item Name="TargetType.ctl" Type="VI" URL="../../Vision/Goal Detection/TargetType.ctl"/>
			<Item Name="Compute Target Distances.vi" Type="VI" URL="../../Vision/Goal Detection/Compute Target Distances.vi"/>
			<Item Name="Label Targets.vi" Type="VI" URL="../../Vision/Goal Detection/Label Targets.vi"/>
			<Item Name="Rank HV combos.vi" Type="VI" URL="../../Vision/Goal Detection/Rank HV combos.vi"/>
			<Item Name="Separate Particles.vi" Type="VI" URL="../../Vision/Goal Detection/Separate Particles.vi"/>
			<Item Name="Score and Rank Target Objects.vi" Type="VI" URL="../../Vision/Goal Detection/Score and Rank Target Objects.vi"/>
			<Item Name="Rectangularity Score.vi" Type="VI" URL="../../Vision/Goal Detection/Rectangularity Score.vi"/>
			<Item Name="Aspect Ratio Score.vi" Type="VI" URL="../../Vision/Goal Detection/Aspect Ratio Score.vi"/>
			<Item Name="Process Image for Target.vi" Type="VI" URL="../../Vision/Goal Detection/Process Image for Target.vi"/>
			<Item Name="Target Detection.vi" Type="VI" URL="../../Vision/Goal Detection/Target Detection.vi"/>
			<Item Name="624WPI Dashboard Video Path.vi" Type="VI" URL="../624WPI Dashboard Video Path.vi"/>
			<Item Name="624WPI_DashboardCreate AVI.vi" Type="VI" URL="../624WPI_DashboardCreate AVI.vi"/>
			<Item Name="624 FPS Calculator.vi" Type="VI" URL="../624 FPS Calculator.vi"/>
			<Item Name="624WPI_CameraRead MJPEG.vi" Type="VI" URL="../624WPI_CameraRead MJPEG.vi"/>
			<Item Name="Named Control.ctl" Type="VI" URL="../Preferences/Named Control.ctl"/>
			<Item Name="Dumb Dashboard Load.vi" Type="VI" URL="../Preferences/Dumb Dashboard Load.vi"/>
			<Item Name="Dumb Dashboard Save.vi" Type="VI" URL="../Preferences/Dumb Dashboard Save.vi"/>
			<Item Name="Label Warnings List.vi" Type="VI" URL="../Preferences/Label Warnings List.vi"/>
			<Item Name="Dumb Dashboard Batch Operation.vi" Type="VI" URL="../Preferences/Dumb Dashboard Batch Operation.vi"/>
			<Item Name="UDP Packet Preferences.vi" Type="VI" URL="../Preferences/UDP Packet Preferences.vi"/>
			<Item Name="Goal Vision Preferences.vi" Type="VI" URL="../Preferences/Goal Vision Preferences.vi"/>
			<Item Name="Get Preferences Archive Path.vi" Type="VI" URL="../Preferences/Get Preferences Archive Path.vi"/>
			<Item Name="Create File.vi" Type="VI" URL="../Preferences/Create File.vi"/>
			<Item Name="Open Preferences File.vi" Type="VI" URL="../Preferences/Open Preferences File.vi"/>
			<Item Name="624_Get All Control References.vi" Type="VI" URL="../Preferences/624_Get All Control References.vi"/>
			<Item Name="GoalVisionCalibrationHelper.vi" Type="VI" URL="../GoalVisionCalibrationHelper.vi"/>
			<Item Name="624WPI_DashboardAdjust Dashboard Window.vi" Type="VI" URL="../624WPI_DashboardAdjust Dashboard Window.vi"/>
			<Item Name="Change Detect Boolean.vi" Type="VI" URL="../../Common Code/Change Detect Boolean.vi"/>
			<Item Name="TimeManager.vi" Type="VI" URL="../../Robot Code/Utilities/TimeManager.vi"/>
			<Item Name="Change Detect Double.vi" Type="VI" URL="../../Common Code/Change Detect Double.vi"/>
			<Item Name="Change Detect String.vi" Type="VI" URL="../../Common Code/Change Detect String.vi"/>
			<Item Name="Change Detect Int.vi" Type="VI" URL="../../Common Code/Change Detect Int.vi"/>
			<Item Name="Change Detect.vi" Type="VI" URL="../../Common Code/Change Detect.vi"/>
			<Item Name="Signal Timer.vi" Type="VI" URL="../../Robot Code/Utilities/Signal Timer.vi"/>
			<Item Name="Single Encoder Data.ctl" Type="VI" URL="../../Robot Code/Sensors/Single Encoder Data.ctl"/>
			<Item Name="Encoder Data.ctl" Type="VI" URL="../../Robot Code/Sensors/Encoder Data.ctl"/>
			<Item Name="Drive Indicators.ctl" Type="VI" URL="../../Common Code/Dashboard UDP/Drive Indicators.ctl"/>
			<Item Name="Halo Indicators.ctl" Type="VI" URL="../../Common Code/Dashboard UDP/Halo Indicators.ctl"/>
			<Item Name="Shooter State.ctl" Type="VI" URL="../../Common Code/Shooter State.ctl"/>
			<Item Name="Shooter Indicators.ctl" Type="VI" URL="../../Common Code/Dashboard UDP/Shooter Indicators.ctl"/>
			<Item Name="IR Logic State.ctl" Type="VI" URL="../../Common Code/IR Logic State.ctl"/>
			<Item Name="Roller Indicators.ctl" Type="VI" URL="../../Common Code/Dashboard UDP/Roller Indicators.ctl"/>
			<Item Name="Auton Indicators.ctl" Type="VI" URL="../../Common Code/Dashboard UDP/Auton Indicators.ctl"/>
			<Item Name="Indicator Packet.ctl" Type="VI" URL="../../Common Code/Dashboard UDP/Indicator Packet.ctl"/>
			<Item Name="Roller Controls.ctl" Type="VI" URL="../../Common Code/Dashboard UDP/Roller Controls.ctl"/>
			<Item Name="Shooter Controls.ctl" Type="VI" URL="../../Common Code/Dashboard UDP/Shooter Controls.ctl"/>
			<Item Name="PID Params.ctl" Type="VI" URL="../../Common Code/Dashboard UDP/PID Params.ctl"/>
			<Item Name="Auton Controls.ctl" Type="VI" URL="../../Common Code/Dashboard UDP/Auton Controls.ctl"/>
			<Item Name="Auto Shift Controls.ctl" Type="VI" URL="../../Common Code/Dashboard UDP/Auto Shift Controls.ctl"/>
			<Item Name="Encoder Controls.ctl" Type="VI" URL="../../Common Code/Dashboard UDP/Encoder Controls.ctl"/>
			<Item Name="Gyro Controls.ctl" Type="VI" URL="../../Common Code/Dashboard UDP/Gyro Controls.ctl"/>
			<Item Name="Camera Controls.ctl" Type="VI" URL="../../Common Code/Dashboard UDP/Camera Controls.ctl"/>
			<Item Name="Dashboard UDP Packet.ctl" Type="VI" URL="../../Common Code/Dashboard UDP Packet.ctl"/>
			<Item Name="Rotate Point.vi" Type="VI" URL="../Field Positioning/Rotate Point.vi"/>
			<Item Name="Field to Pixel.vi" Type="VI" URL="../Field Positioning/Field to Pixel.vi"/>
			<Item Name="Draw Bot.vi" Type="VI" URL="../Field Positioning/Draw Bot.vi"/>
			<Item Name="Draw Goals.vi" Type="VI" URL="../Field Positioning/Draw Goals.vi"/>
			<Item Name="Draw Aimpoint.vi" Type="VI" URL="../Field Positioning/Draw Aimpoint.vi"/>
			<Item Name="Draw Axes.vi" Type="VI" URL="../Field Positioning/Draw Axes.vi"/>
			<Item Name="Field Drawing.vi" Type="VI" URL="../Field Positioning/Field Drawing.vi"/>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="FRC PC Dashboard" Type="EXE">
				<Property Name="App_INI_aliasGUID" Type="Str">{47BAFDCE-3F99-4134-9347-62A4C9A5434C}</Property>
				<Property Name="App_INI_GUID" Type="Str">{76D91052-50F0-4E0B-B76F-616DDC550CED}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{56AA9368-84D4-42E1-9CCF-4FA34A518587}</Property>
				<Property Name="Bld_buildSpecDescription" Type="Str">Build Dashboard Main.vi into an EXE that will respond to the driver station and display robot information on a PC.</Property>
				<Property Name="Bld_buildSpecName" Type="Str">FRC PC Dashboard</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/FRC Dashboard Project/FRC PC Dashboard</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{F12754D6-B5E0-496F-B50C-3EDB6F368199}</Property>
				<Property Name="Bld_version.build" Type="Int">12</Property>
				<Property Name="Bld_version.major" Type="Int">5</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/FRC Dashboard Project/FRC PC Dashboard/Dashboard.exe</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/FRC Dashboard Project/FRC PC Dashboard/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Exe_iconItemID" Type="Ref">/My Computer/Support/App EXE.ico</Property>
				<Property Name="Source[0].itemID" Type="Str">{5E07FFF1-634C-42BF-B61D-AADD37850173}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_fileDescription" Type="Str">FRC PC Dashboard</Property>
				<Property Name="TgtF_internalName" Type="Str">FRC PC Dashboard</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{AEE2EF3D-7087-47D6-AEAE-9F87F896ED5E}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
		</Item>
	</Item>
</Project>
