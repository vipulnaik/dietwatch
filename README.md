# dietwatch

A tracker for people's thoughts and state transitions related to diet,
as well as the personal health, animal welfare, and environmental
perspectives

The portal to access the data is at
[dietwatch.vipulnaik.com](https://dietwatch.vipulnaik.com/).

## Setting up

This section is for people who want to set up a local mirror of the
dietwatch portal (e.g., for development
purposes) or want to load up the data into a local database to run
their own queries.

Note that the `passwordFile.inc` file in
`access-portal/backend/globalVariables` is excluded from the Git
repository, but you can modify a corresponding dummy password file at
[`dummyPasswordFile.inc`](https://github.com/vipulnaik/dietwatch/blob/master/access-portal/backend/globalVariables/dummyPasswordFile.inc):

```bash
cp access-portal/backend/globalVariables/{dummyPasswordFile.inc,passwordFile.inc}
vi access-portal/backend/globalVariables/passwordFile.inc # change to add database login info
```

The database name is present both in dummyPasswordFile.inc and in the
Makefile, so if you want a name other than `dietwatch`, you should
edit the name in both places.

You can create the `dietwatch` database either directly in MySQL or
by running this from the root folder of this repository, after
updating MYSQL_ARGS in the Makefile (such as `-u<username>
-p<password>`):

```bash
make init
```

Instead of editing the Makefile, you can also pass in the arguments to
make:

```bash
make MYSQL_ARGS=<args> init
```

### Loading and refreshing data

Once you already have the `dietwatch` SQL database set up, you can update
the MYSQL_ARGS in the Makefile (such as `-u<username> -p<password>`)
and you can then load the data using:

```bash
make reset && make read
```

Instead of editing the Makefile, you can also pass in the arguments to
each make:

```bash
make MYSQL_ARGS=<args> reset && make MYSQL_ARGS=<args> read
```

### Table sorting

To get files for table sorting, run:

```bash
make fetch_table_sorting
```

You can remove these files with `make clean_table_sorting`.

### AnchorJS

To get AnchorJS, run:

```bash
make fetch_anchorjs
```

You can remove these files with `make clean_anchorjs`.
