bool is_char_alphanum(char ch) {
  int is_num = ch >= '0' && ch <= '9';
  int is_alpha = (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
  if (!is_alpha && !is_num) {
    return false;
  }
  return true;
}

bool is_url(char *str) {
  return str[0] == 'h' && str[1] == 't' && str[2] == 't' && str[3] == 'p';
}

bool is_templated(char *str) {
  int i;
  int len = strlen(str);
  for (i = 0; i < len; i++) {
    if (str[i] == '{') {
      return true;
    }
  }
  return false;
}

bool file_exists(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file != NULL) {
    fclose(file);
    return true;
  }
  return false;
}

bool is_alphanum(char *str) {
  int i;
  int len = strlen(str);
  for (i = 0; i < len; i++) {
    char ch = str[i];
    int is_num = ch >= '0' && ch <= '9';
    int is_alpha = (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    int is_space = (ch == ' ');
    if (!is_alpha && !is_num && !is_space) {
      return false;
    }
  }
  return true;
}

bool is_plaintext(char *str) {
  int i;
  int len = strlen(str);
  for (i = 0; i < len; i++) {
    char ch = str[i];
    int is_num = ch >= '0' && ch <= '9';
    int is_alpha = (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    int is_space =
        (ch == ' ' || ch == '_' || ch == '.' || ch == ',' || ch == '-');
    if (!is_alpha && !is_num && !is_space) {
      return false;
    }
  }
  return true;
}

void to_lowercase(char *src, char *dest) {
  int i;
  int len = strlen(src) + 1;
  for (i = 0; i < len; i++) {
    dest[i] = src[i];
    if (dest[i] == '\0') {
      break;
    }
    dest[i] = tolower(dest[i]);
  }
  dest[len - 1] = '\0';
}

void to_alphanum(char *src, char *dest) {
  int i;
  int len = strlen(src) + 1;
  for (i = 0; i < len; i++) {
    dest[i] = src[i];
    if (dest[i] == '\0') {
      break;
    }
    if (!is_char_alphanum(dest[i])) {
      dest[i] = ' ';
    } else {
      dest[i] = tolower(dest[i]);
    }
  }
  dest[len - 1] = '\0';
}

void to_uppercase(char *str, char *target, int size) {
  int i;
  for (i = 0; i < size; i++) {
    target[i] = str[i];
    if (target[i] == '\0') {
      break;
    }
    target[i] = toupper(target[i]);
  }
  target[size - 1] = '\0';
}

void to_filename(char *str, char *mod) {
  int i;
  int len = strlen(str) + 1;
  for (i = 0; i < len; i++) {
    mod[i] = str[i];
    if (mod[i] == '\0') {
      break;
    }
    if (!is_char_alphanum(mod[i])) {
      mod[i] = '_';
    } else {
      mod[i] = tolower(mod[i]);
    }
  }
  mod[len - 1] = '\0';
}

int index_of_int(int a[], int num_elements, int value) {
  int i;
  for (i = 0; i < num_elements; i++) {
    if (a[i] == value) {
      return i;
    }
  }
  return -1;
}

int index_of_string(char *a[], int num_elements, char *value) {
  int i;
  for (i = 0; i < num_elements; i++) {
    if (strcmp(a[i], value) == 0) {
      return i;
    }
  }
  return -1;
}

int index_of_char(char *str, char target) {
  int i;
  int len = strlen(str);
  for (i = 0; i < len; i++) {
    if (str[i] == target) {
      return i;
    }
  }
  return -1;
}

int countLeadingSpaces(char *str) {
  int i;
  int len = strlen(str) + 1;
  for (i = 0; i < len; i++) {
    if (str[i] != ' ') {
      return i;
    }
  }
  return -1;
}

void substr(char *src, char *dest, int from, int to) {
  memcpy(dest, src + from, to);
  dest[to] = '\0';
}

char *trimstr(char *str) {
  char *end;
  while (isspace((unsigned char)*str))
    str++;
  if (*str == 0)
    return str;
  end = str + strlen(str) - 1;
  while (end > str && isspace((unsigned char)*end))
    end--;
  end[1] = '\0';
  return str;
}

float find_average(int a[]) {
  int i;
  int sum = 0;
  for (i = 0; i < 52; ++i) {
    sum += a[i];
  }
  return sum / 52;
}

float clamp_float(float v, float min, float max) {
  return v > max ? max : v < min ? min : v;
}

int clamp_int(int v, int min, int max) {
  return v > max ? max : v < min ? min : v;
}

int extract_year(char *arvelie) {
  int result = 0, i = 0;
  for (i = 0; i < 2; i++) {
    result = result * 10 + (arvelie[i] - '0');
  }
  return result;
}

int doty_to_month(int doty) {
  int month = 0;
  int months[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
  while (months[month] < doty) {
    month++;
  }
  return month - 1;
}

int doty_to_day(int doty) {
  int month = 0;
  int months[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
  while (months[month] < doty) {
    month++;
  }
  return doty - months[month - 1];
}

void fputs_rfc2822(FILE *f, char *arvelie) {
  time_t current;
  int doty = arvelie_to_doty(arvelie);
  int year = extract_year(arvelie);
  int month = doty_to_month(doty);
  int day = doty_to_day(doty);
  char rfc_2822[40];
  struct tm str_time;
  str_time.tm_year = (2000 + year) - 1900;
  str_time.tm_mon = month;
  str_time.tm_mday = day;
  str_time.tm_hour = 0;
  str_time.tm_min = 0;
  str_time.tm_sec = 0;
  str_time.tm_isdst = 0;
  current = mktime(&str_time);
  strftime(rfc_2822, sizeof(rfc_2822), "%a, %d %b %Y 00:00:00 +0900",
           localtime(&current));
  fprintf(f, "%s", rfc_2822);
}

float clock_since(clock_t start) {
  double cpu_time_used = ((double)(clock() - start)) / CLOCKS_PER_SEC;
  return cpu_time_used * 1000;
}
