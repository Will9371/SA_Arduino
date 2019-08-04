struct SimpleChime
{
  int noteCount = 8;
  int notes[8] = { NOTE_C5, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, 0, NOTE_B4, NOTE_C5 };
  int timeSignature[8] = { 4, 8, 8, 4, 4, 4, 4, 4 };
};

struct LowChime
{
  int noteCount = 8;
  int notes[8] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4 };
  int timeSignature[8] = { 4, 8, 8, 4, 4, 4, 4, 4 };
};
