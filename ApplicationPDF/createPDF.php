<?php
require('fpdf17/fpdf.php');

# Arguments
$name = $argv[1];
$address1 = $argv[2];
$address2 = $argv[3];
$city = $argv[4];
$state = $argv[5];
$zip = $argv[6];
$country = $argv[7];
$email = $argv[8];
$phone = $argv[9];
$undergrad = $argv[10];
$major = $argv[11];
$grad = $argv[12];
$degree = $argv[13];
$year = $argv[14];
$current = $argv[15];
$past = $argv[16];
$offices = $argv[17];
$awards = $argv[18];
$ec = $argv[19];
$choice = $argv[20];
$interests = $argv[21];
$goals = $argv[22];
$previous = $argv[23];
$again = $argv[24];
$request = $argv[25];
$skype = $argv[26];

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
$pdf->Cell(30, 5,'Committee:');
$pdf->SetFont('Arial','',14);
$pdf->Cell(50,5,$choice,0,1);
$pdf->Ln(3);
$pdf->SetFont('Arial','B',12);
$pdf->MultiCell(0,4,'The nature and extent of the applicant\'s interest in the position they listed as their choice.');
$pdf->Ln(2);
$pdf->SetFont('Arial','',11);
$pdf->MultiCell(0,4,$interests);

$pdf->Ln(4);
#---------------------------------------------
# goals
$pdf->SetFont('Arial','B',12);
$pdf->MultiCell(0,4,'The specific goals and ideas that this applicant has for the position they listed as their choice.');
$pdf->Ln(2);
$pdf->SetFont('Arial','',11);
$pdf->MultiCell(0,4,$goals);

$pdf->Ln(4);
#---------------------------------------------
# previous
$pdf->SetFont('Arial','B',12);
$pdf->MultiCell(0,4,'Whether the applicant has been a member of the committee');
$pdf->Ln(2);
$pdf->SetFont('Arial','',11);
$pdf->MultiCell(0,4,$previous);

$pdf->Ln(4);
$x = $pdf->GetX();
$y = $pdf->GetY();
$pdf->Line($x, $y, $x+190, $y);
$pdf->Ln(4);

#---------------------------------------------
# phone
$pdf->SetFont('Arial','B',12);
$pdf->MultiCell(0,4,'Does the applicant request a phone interview?');
$pdf->Ln(2);
$pdf->SetFont('Arial','',11);
$pdf->MultiCell(0,4,$request);

$pdf->Ln(4);
#---------------------------------------------
# skype
$pdf->SetFont('Arial','B',12);
$pdf->MultiCell(0,4,'Skype username:');
$pdf->Ln(2);
$pdf->SetFont('Arial','',11);
$pdf->MultiCell(0,4,$skype);

$pdf->Output();
?>