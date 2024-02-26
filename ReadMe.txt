Datum Shift Issues for Canadian Users

This text file discusses issues concerning geodetic grid interpolation
data files which are supported by Autodesk products, but which are not distributed
with Autodesk products. In the absence of a any of the actions described in this
file, the datum shift portion of the coordinate conversion process of
Canadian geographic features will be processed as indicated by the
fallback specification located in the NAD27_to_NAD83 Geodetic Transformation.

The coordinate system software automatically performs a datum shift if 
the source and destination coordinate systems use different datums. 
Within North America, this is most often a shift between the NAD27 and 
NAD83 datums.  For U.S. users, CS-MAP, the coordinate system engine used
internally, uses the freely distributable
NADCON data files supplied by USGS.

Both  versions of the Canadian National Transformation are supported,
but use of version 1 is strongly discouraged by Geomatics Canada and
should be avoided.  Neither of these files are included in the CS-MAP
distribution as the publisher, Geomatics Canada, requires that you register
with them before granting permission to use the file.  There is no fee, only
registration as a user is required.  You will not be able to obtain a copy of
the version 1 file from Geomatics Canada under any circumstances.

To use version 2 of the Canadian National Transformation, you need to
perform the following steps:

1.  Obtain a copy of the data file.  Contact:

	Information Services
	Geodetic Survey Division, Geomatics Canada
	615 Booth Street
	Ottawa, Ontario, K1A 0E9
	(613) 995-4410
	information@geod.nrcan.gc.ca
	http://www.geod.nrcan.gc.ca.

2.  Once you have the file, copy it into the coordinate system dictionary
folder hierarchy, preferably at Canada (this is the same directory where
this ReadMe.txt file was installed) and name it “Ntv2_0.gsb”.
This coordinate system folder is typically 
"c:\ProgramData\Autodesk\Geospatial Coordinate Systems"
on a Windows 7 machine.

3. For Autodesk products 2010 or earlier, we used to have to open the file 
Nad27ToNad83.gdc (located in the some directory
as the coordinate system dictionary files) with some text editor
program such as Notepad.  Find the section labeled "CANADA SPECIFIC
NOTES."  Delete the initial "#" symbol from the line that begins:
#.\Canada\Ntv2_0.gsb

For Autodesk products 2011 or later you need to modify the definition of the Geodetic Transformation
named "NAD27_to_NAD83". Essentially you will need to edit that definition to
include a reference to the newly installed Ntv2_0.gsb file. 

- In AutoCAD Map 3D, run the command MAPCSLIBRARY, or press the "Library" button in 
the ribbon located inside the "Coordinate System" panel.
- locate the Geodetic Transformation "NAD27_to_NAD83", and select it
- press the "Edit" button
- select the "Grid Data File Interpolation" item in the left pane
- choose the "Grid File Format" "Canadian NTv2" in the combo box
- press the "+" button
- select the Canadian grid file and add it to the list

This dialog box is also where you can specify a different fallback transformation mentioned
at the beginning of this readme file.

The NAD27 to NAD83 transformation data files overlap.  In the region of
overlap, the various files will not produce exactly the same results.
You may indicate which data file is to take precedence by sequencing the 
file references in the order of precedence.  Overlap in this specific case
occurs between the NTV2_0.gsb file and the CONUS.L?S files (especially in
and around the Detroit area) and between the NTV2_0.gsb file and the
ALASKA.L?S files along the common border between Canada and Alaska.
To change the order of the grid files use the up and down arrow buttons 
on the right side of list of grid files.

- Once your list of grid files is correct, press the save button and
close the coordinate system library dialog box

The procedure to use datum shift files provided by a provincial government
is similar to the above.  You must first obtain the file, copy it into a logical
location in the dictionary folder hierarchy, and then make AutoCAD Map aware of
the existence and location of the file by editing the appropriate Geodetic
Transformation as described above.
