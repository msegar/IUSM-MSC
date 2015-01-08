<?php
require('fpdf17/fpdf.php');

# Arguments
$name = $argv[1];
$year = $argv[2];
$email = $argv[3];
$phone = $argv[4];
$current = $argv[5];
$past = $argv[6];
$undergrad = $argv[7];
$major = $argv[8];
$grad = $argv[9];
$degree = $argv[10];
$offices = $argv[11];
$awards = $argv[12];
$ec = $argv[13];
$choice1 = $argv[14];
$interests1 = $argv[15];
$goals1 = $argv[16];
$previous1 = $argv[17];

$pdf = new FPDF();
$pdf->AddPage();
$pdf->SetFont('Arial','B',22);
$pdf->Cell(60,20,$name,0,1);

# Class Year
$pdf->SetFont('Arial','B',12);
$pdf->Cell(21, 8,'Year:');
$pdf->SetFont('Arial','',12);
$pdf->Cell(10,8,$year,0,1);

$pdf->Ln(4);

#---------------------------------------------
# Email
$pdf->SetFont('Arial','B',12);
$pdf->Cell(21, 8,'Email:');
$pdf->SetFont('Arial','',12);
$pdf->Cell(53,8,$email,0,0);

# Current Campus
$pdf->SetFont('Arial','B',12);
$pdf->Cell(40, 8,'Current Campus:');
$pdf->SetFont('Arial','',12);
$pdf->Cell(15,8,$current,0,1);
#---------------------------------------------
# Phone
$pdf->SetFont('Arial','B',12);
$pdf->Cell(21, 4,'Phone:');
$pdf->SetFont('Arial','',12);
$pdf->Cell(53,4,$phone,0,0);

# Past Campus
$pdf->SetFont('Arial','B',12);
$pdf->Cell(40, 4,'Past Campus:');
$pdf->SetFont('Arial','',12);
$pdf->Cell(15,4,$past,0,1);

$pdf->Ln(6);

#---------------------------------------------
# Undergrad Institution
$pdf->SetFont('Arial','B',12);
$pdf->Cell(50, 8,'Undergrad. Institution:');
$pdf->SetFont('Arial','',12);
$pdf->Cell(50,8,$undergrad,0,1);

# Undergrad Degree
$pdf->SetFont('Arial','B',12);
$pdf->Cell(50, 4,'Undergrad. Major:');
$pdf->SetFont('Arial','',12);
$pdf->Cell(50,4,$major,0,1);
#---------------------------------------------
# Graduate Institution
$pdf->SetFont('Arial','B',12);
$pdf->Cell(50, 8,'Graduate Institution:');
$pdf->SetFont('Arial','',12);
$pdf->Cell(50,8,$grad,0,1);

# Undergrad Degree
$pdf->SetFont('Arial','B',12);
$pdf->Cell(50, 4,'Graduate Degree(s):');
$pdf->SetFont('Arial','',12);
$pdf->Cell(50,4,$degree,0,1);

$pdf->Ln(6);
#---------------------------------------------
# Offices held
$pdf->SetFont('Arial','B',12);
$pdf->MultiCell(0,4,'Offices held, committee appointments, and prior leadership experience while in medical school and/or at previous undergraduate or graduate institutions.');
$pdf->Ln(2);
$pdf->SetFont('Arial','',11);
$pdf->MultiCell(0,4,$offices);

$pdf->Ln(4);
#---------------------------------------------
# Awards
$pdf->SetFont('Arial','B',12);
$pdf->MultiCell(0,4,'Awards, honors, or other distinctions received while in medical school and/or at the applicant\'s undergraduate or graduate institutions.');
$pdf->Ln(2);
$pdf->SetFont('Arial','',11);
$pdf->MultiCell(0,4,$awards);

$pdf->Ln(4);
#---------------------------------------------
# Extracurriculars
$pdf->SetFont('Arial','B',12);
$pdf->MultiCell(0,4,'Extracurricular activities and interests:');
$pdf->Ln(2);
$pdf->SetFont('Arial','',11);
$pdf->MultiCell(0,4,$ec);

$pdf->Ln(4);
$x = $pdf->GetX();
$y = $pdf->GetY();
$pdf->Line($x, $y, $x+190, $y);

$pdf->Ln(4);
#-------------------------------------------------------------------------------------------------------
# Applicant's Choice
$pdf->SetFont('Arial','B',14);
$pdf->Cell(50, 5,'Applicant\'s Choice:');
$pdf->SetFont('Arial','',14);
$pdf->Cell(50,5,$choice1,0,1);
$pdf->Ln(3);
$pdf->SetFont('Arial','B',12);
$pdf->MultiCell(0,4,'The nature and extent of the applicant\'s interest in the position they listed as their choice.');
$pdf->Ln(2);
$pdf->SetFont('Arial','',11);
$pdf->MultiCell(0,4,$interests1);

$pdf->Ln(4);
#---------------------------------------------
# goals
$pdf->SetFont('Arial','B',12);
$pdf->MultiCell(0,4,'The specific goals and ideas that this applicant has for the position they listed as their choice.');
$pdf->Ln(2);
$pdf->SetFont('Arial','',11);
$pdf->MultiCell(0,4,$goals1);

$pdf->Ln(4);
#---------------------------------------------
# previous
$pdf->SetFont('Arial','B',12);
$pdf->MultiCell(0,4,'Whether the applicant has been a member of the committee');
$pdf->Ln(2);
$pdf->SetFont('Arial','',11);
$pdf->MultiCell(0,4,$previous1);

$pdf->Output();
?>