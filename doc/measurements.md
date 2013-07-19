# Board measurements

Parameters

    height inside = 3cm
    panel width = 20cm
    panel height = 15cm
    panel horizontal border = 2cm
    panel vertical border = 3cm
    panel angle = pi / 9 
    wood thickness = 0.5cm
    stiffener thickness = 1.5cm
    saw width = 0.1cm


Intermediary products and functions

    surface = width * height

    panel climb = sin(panel angle) * panel height
                => 5.13cm

    base width = panel width
    base height = cos(panel angle) * panel height
               => 14.1cm
    
    front height = height inside + wood thickness
    back height = front height + panel climb

    climb on back stiffener = tan(panel angle) * stiffener thickness
                            => 0.55cm
    
    max(x, y) = if x > y then x else y
    min(x, y) = if x < y then x else y


## Resulting measurements

Part 1: back vertical stiffener

    p1 length = back height - climb on back stiffener - wood thickness
              => 7.58cm

Part 2: front vertical stiffener

    p2 length = front height - wood thickness
              => 3cm
    
Part 3: side stiffener

    p3 length = base height - 2 * (stiffener thickness + wood thickness)
              => 10.1cm
    
Part 4: back stiffener

    p4 length = base width - 2 * (stiffener thickness + wood thickness)
              => 16cm

Part 5: side board
    
    p5 width = base height
             => 14.1cm
    p5 front height = front height + wood thickness
                    => 4cm
    p5 back height = height inside + panel climb + wood thickness
                   => 8.63cm

Part 6: back board

    p6 width = base width - 2 * wood thickness
             => 19cm
    p6 height = back height
              => 8.63cm

Part 7: front board

    p7 width = base width - 2 * wood thickness
             => 19cm
    p7 height = front height
              => 3.5cm

Part 9: bottom board

    p9 width = base width - 2 * wood thickness
             => 19cm
    p9 height = base height - 2 * wood thickness
              => 13.1cm

Part 10: panel

    p10 width = panel width + 2 * panel horizontal border
              => 24cm
    p10 height = panel height + 2 * panel vertical border
               => 21cm

Board surface

              
    p5 height diff = p5 back height - p5 front height
                   => 4.63cm
    
    p5 surface = p5 width * p5 front height + (p5 width * p5 height diff) / 2
               => 89.01cm^2

    p6 surface = p6 width * p6 height
    p7 surface = p7 width * p7 height
    p9 surface = p9 width * p9 height
    p10 surface = p10 width * p10 height

Totals & required material

    total stiffener length = p1 length + p2 length + p3 length + p4 length + 3 * saw width
                           => 36.98cm

    total board surface = p5 surface + p6 surface + p7 surface + p9 surface + p10 surface
                        => 1072.3cm^2
    
    base board required width = max(base width/cm, min(p10 width/cm, p10 height/cm)) * cm
                              => 21cm
    base board required height = p5 front height + p5 back height # the two side plates
                               + p6 height + p7 height + p9 height
                               + max(p10 width/cm, p10 height/cm) * cm
                               + 5 * saw width
                               => 62.36cm