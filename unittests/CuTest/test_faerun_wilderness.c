#include "CuTest.h"

#include "../../src/conf.h"
#include "../../src/sysdep.h"
#include "../../src/structs.h"
#include "../../src/utils.h"
#include "../../src/db.h"
#include "../../src/perlin.h"
#include "../../src/wilderness.h"

#include <stdio.h>
#include <stdlib.h>

static const char *faerun_test_source_root(void)
{
  const char *root;

  root = getenv("LUMINARI_TEST_ROOT");
  return root != NULL && *root != '\0' ? root : ".";
}

void Test_faerun_wilderness_image_and_legend(CuTest *tc)
{
#ifdef CAMPAIGN_FR
  static const int expected_sectors[] = {
      SECT_OCEAN,       SECT_FIELD,  SECT_FOREST,     SECT_HILLS,
      SECT_MOUNTAIN,    SECT_DESERT, SECT_WATER_SWIM, SECT_MARSHLAND,
      SECT_TUNDRA,      SECT_ROAD_EW, SECT_ROAD_NS,   SECT_ROAD_INT,
      SECT_JUNGLE,      SECT_BEACH,
  };
  size_t sector_counts[NUM_ROOM_SECTORS] = {0};
  char image_filename[PATH_MAX];
  char legend_filename[PATH_MAX];
  char *large_map;
  const char *cursor;
  int height;
  int line_count;
  int sector_type;
  int width;
  int x;
  int y;
  size_t i;

  snprintf(image_filename, sizeof(image_filename), "%s/frmaps/faerunmap.jpg",
           faerun_test_source_root());
  snprintf(legend_filename, sizeof(legend_filename), "%s/frmaps/legend.txt",
           faerun_test_source_root());

  destroy_faerun_wilderness_map();
  CuAssertTrue(tc, load_faerun_wilderness_map(image_filename, legend_filename));

  width = get_faerun_wilderness_width();
  height = get_faerun_wilderness_height();
  CuAssertIntEquals(tc, 1248, width);
  CuAssertIntEquals(tc, 1023, height);
  CuAssertTrue(tc, wilderness_coordinates_valid(0, 0));
  CuAssertTrue(tc, wilderness_coordinates_valid(width - 1, height - 1));
  CuAssertTrue(tc, !wilderness_coordinates_valid(-1, 0));
  CuAssertTrue(tc, !wilderness_coordinates_valid(width, 0));
  CuAssertTrue(tc, !wilderness_coordinates_valid(0, height));

  for (y = 0; y < height; y++)
  {
    for (x = 0; x < width; x++)
    {
      CuAssertTrue(tc, get_faerun_wilderness_sector(x, y, &sector_type));
      CuAssertTrue(tc, sector_type >= 0 && sector_type < NUM_ROOM_SECTORS);
      sector_counts[sector_type]++;
    }
  }

  for (i = 0; i < sizeof(expected_sectors) / sizeof(expected_sectors[0]); i++)
    CuAssertTrue(tc, sector_counts[expected_sectors[i]] > 0);

  CuAssertTrue(tc, get_faerun_wilderness_sector(624, height - 1, &sector_type));
  CuAssertIntEquals(tc, SECT_TUNDRA, sector_type);

  init_perlin(NOISE_WEATHER, NOISE_WEATHER_SEED);
  large_map = gen_ascii_wilderness_map(201, 624, 511, MAP_TYPE_NORMAL);
  CuAssertPtrNotNull(tc, large_map);
  if (large_map)
  {
    line_count = 0;
    for (cursor = large_map; *cursor; cursor++)
      if (*cursor == '\n')
        line_count++;
    CuAssertIntEquals(tc, 201, line_count);
    CuAssertTrue(tc, strlen(large_map) > 32768);
    free(large_map);
  }

  destroy_faerun_wilderness_map();
#else
  CuAssertTrue(tc, TRUE);
#endif
}

void Test_faerun_wilderness_pool_enables_zone_services(CuTest *tc)
{
#ifdef CAMPAIGN_FR
  struct room_data rooms[2];
  struct zone_data zones[1];
  struct room_data *saved_world;
  struct zone_data *saved_zone_table;
  room_rnum saved_top_of_world;
  zone_rnum saved_top_of_zone_table;
  bool exits_valid = true;
  bool wilderness_enabled;
  int prepared;
  int direction;

  memset(rooms, 0, sizeof(rooms));
  memset(zones, 0, sizeof(zones));
  rooms[0].number = WILD_ROOM_VNUM_START;
  rooms[0].zone = 0;
  rooms[1].number = WILD_DYNAMIC_ROOM_VNUM_START;
  rooms[1].zone = 0;
  zones[0].number = 10000;

  saved_world = world;
  saved_top_of_world = top_of_world;
  saved_zone_table = zone_table;
  saved_top_of_zone_table = top_of_zone_table;
  world = rooms;
  top_of_world = 1;
  zone_table = zones;
  top_of_zone_table = 0;

  prepared = prepare_faerun_dynamic_room_pool();
  wilderness_enabled = ZONE_FLAGGED(0, ZONE_WILDERNESS);
  for (direction = NORTH; direction <= WEST; direction++)
  {
    if (!rooms[1].dir_option[direction])
    {
      exits_valid = false;
      continue;
    }
    if (rooms[1].dir_option[direction]->to_room != 0)
      exits_valid = false;
    free(rooms[1].dir_option[direction]);
  }

  world = saved_world;
  top_of_world = saved_top_of_world;
  zone_table = saved_zone_table;
  top_of_zone_table = saved_top_of_zone_table;

  CuAssertTrue(tc, prepared);
  CuAssertTrue(tc, wilderness_enabled);
  CuAssertTrue(tc, exits_valid);
#else
  CuAssertTrue(tc, TRUE);
#endif
}
